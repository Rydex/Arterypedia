#include "menu.h"
#include <ncurses/curses.h>
#include <sstream>

void Menu::show() {
  clear();
  getmaxyx(stdscr, max_visible_ln, std::ignore);

  int avail_ln = max_visible_ln - choices.size() - 3; // 3 for headers (branches, supply, origin)

  attron(A_BOLD);
  printw("%s", title.c_str());
  attroff(A_BOLD);

  if(!supply.empty() && !branches.empty() && !origin.empty()) {
    attron(A_BOLD);
    printw("\n\nBranches: ");
    attroff(A_BOLD);
    printw("%s", branches.c_str());
    attron(A_BOLD);
    printw("\nSupply: ");
    attroff(A_BOLD);
    printw("%s", supply.c_str());
    attron(A_BOLD);
    printw("\nOrigin: ");
    attroff(A_BOLD);
    printw("%s", origin.c_str());
  }

  if(!choices.empty()) {
    for(int i=0; i<(int)choices.size(); i++) {
      std::ostringstream oss;
      oss << "\n[" << i+1 << "]. " << choices[i];
              
      if(i == current_choice_index) {
        attron(COLOR_PAIR(1));
        printw("%s", oss.str().c_str());
        attroff(COLOR_PAIR(1));
      } else {
        printw("%s", oss.str().c_str());
      }
    }
  }

  if(!text.empty()) {
    std::istringstream iss(text);
    std::string line;
    int ln_count = 0;
    int cur_ln = 0;

    while(std::getline(iss, line)) ln_count++;
    iss.clear();
    iss.seekg(0);

    while(std::getline(iss, line) && cur_ln < text_start_ln + avail_ln) {
      if(cur_ln >= text_start_ln) {
        printw("\n%s", line.c_str());
      }
      cur_ln++;
    }

    // show scroll indicator
    if(ln_count > avail_ln) {
      int scroll_percent = (text_start_ln * 100) / (ln_count - avail_ln);
      printw("\n\n[Scrolled: %d%%]", scroll_percent);
    }
  }

  if(!related.empty()) {
    printw("\n");
    attron(A_BOLD);
    printw("\nRelated topics:\n");
    attroff(A_BOLD);
    for(int i=0; i<(int)related.size(); i++) {
      std::ostringstream oss;
      oss << related[i];
      if(i != (int)related.size()-1) {
        oss << '\n';
      }

      attron(A_UNDERLINE);
      printw("%s", oss.str().c_str());
      attroff(A_UNDERLINE);
    }
  }
  refresh();

  if(is_submenu) {
    printw("\n\n");
    attron(COLOR_PAIR(1));
    printw("b");
    attroff(COLOR_PAIR(1));
    printw(" [B]ack to main menu");
  } else {
    printw("\n");
  }
  printw("\n");
  attron(COLOR_PAIR(1));
  printw("q");
  attroff(COLOR_PAIR(1));
  printw(" [Q]uit");
  refresh();
}

void Menu::scroll_text_up() {
  if(text_start_ln > 0) {
    text_start_ln--;
  }
}

void Menu::scroll_text_down() {
  std::istringstream iss(text);
  std::string line;
  int ln_count = 0;
  while(std::getline(iss, line)) ln_count++;

  if(text_start_ln < ln_count - max_visible_ln + choices.size() + 3) {
    text_start_ln++;
  }
}

// takes care of user input
void Menu::run() {
  bool in_menu = true;
  while(in_menu) {
    show();
    int ch = getch();

    if(ch == KEY_DOWN) {
      if(!choices.empty() && current_choice_index < (int)choices.size() - 1) {
        current_choice_index++;
      } else {
        scroll_text_down(); // scroll down if at the bottom of choice list
      }
    } else if(ch == KEY_UP) {
      if(!choices.empty() && current_choice_index > 0) {
        current_choice_index--;
      } else {
        scroll_text_up(); // scroll up if at the topmost of choice list
      }
    } else if(ch == '\n' || ch == KEY_ENTER) {
      if(!actions.empty()) {
        actions[current_choice_index]();
      }
    } else if(ch == 'b' && is_submenu) {
      in_menu = false;
      text_start_ln = 0; //reset when leaving
    } else if(ch == 'q') {
      endwin();
      exit(0);
    }
  }
}

decltype(Menu::choices) Menu::get_choices() const {
  return choices;
}

void print(const std::string& text) {
  clear(); 
  printw("%s", text.c_str());
  refresh(); 
  getch(); 
}
