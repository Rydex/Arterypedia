#include "menu.h"
#include <ncurses/curses.h>
#include <sstream>

void Menu::show() {
  clear();
  attron(A_BOLD);
  printw("%s", title.c_str());
  attroff(A_BOLD);

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
  } else {
    printw("%s", text.c_str());
  }

  if(!related.empty()) {
    printw("\n");
    attron(A_BOLD);
    printw("Related topics:\n\n");
    attroff(A_BOLD);
    for(int i=0; i<(int)related.size(); i++) {
      std::ostringstream oss;
      oss << related[i] << '\n';

      attron(A_UNDERLINE);
      printw("%s", oss.str().c_str());
      attroff(A_UNDERLINE);
    }
  }
  refresh();

  if(is_submenu) {
    printw("\n\n[b]. Back to main menu");
  }
  printw("\n[q]. Quit");
  refresh();
}

void Menu::run() {
  bool in_menu = true;
  while(in_menu) {
    show();
    int ch = getch();

    if(ch == KEY_DOWN && current_choice_index < (int)choices.size() - 1) {
      current_choice_index++;
    } else if(ch == KEY_UP && current_choice_index > 0) {
      current_choice_index--;
    } else if(ch == '\n' || ch == KEY_ENTER) {
      if(!actions.empty()) {
        actions[current_choice_index]();
      }
    } else if(ch == 'b' && is_submenu) {
      in_menu = false;
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
