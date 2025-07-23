#include <functional>
#include <ncurses/curses.h>
#include <sstream>
#include <string>
#include <memory>

class Menu {
private:
  std::string title, text;
  std::vector<std::string> choices;
  bool is_submenu;
  int current_choice_index = 0;
    
public:
  std::vector<std::function<void()>> actions;
  Menu(
    const std::string& title,
    const std::vector<std::string>& choices,
    const std::vector<std::function<void()>>& actions,
    bool is_submenu=false
  ) : title(title), choices(choices), is_submenu(is_submenu), actions(actions) {}

  Menu(
    const std::string& title,
    const std::string& text
  ): title(title), text(text), choices(), is_submenu(true) {}

  Menu& set_text(const std::string& text) {
    this->text = text;
    return *this;
  }

  void show() {
    clear();
    attron(A_BOLD);
    printw("%s", title.c_str());
    attroff(A_BOLD);

    if(!choices.empty()) {
      for(int i = 0; i < (int)choices.size(); i++) {
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

    if(is_submenu) {
      printw("\n\n[b]. Back to main menu");
    }
    printw("\n[q]. Quit");
    refresh();
  }

  void run() {
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

  std::vector<std::string> get_choices() const {
    return choices;
  }
};

void print(const std::string& text) {
  clear(); 
  printw("%s", text.c_str());
  refresh(); 
  getch(); 
}

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);

  auto carotid_sinus = std::make_shared<Menu>(
    "Carotid Sinus",
    "\n\n The carotid sinus is a baroreceptor. This allows for homeostatic mechanisms to monitor \
blood pressure. The baroreceptors inside the sinus are innervated by the glossopharyngeal \
nerve (CN IX).\n\n \
It is a very sensitive site of the body as stimulation can drive large-scale reflex effects \
throughout the body. Physical assault occuring at this point produces massive baroflex \
activation and can cause cerebral ischemia.\n\n \
The sinus often has artherosclerotic plaques because of disturbed hemodynamics. Because \
of these plaques, which can lead to ischemic strokes and transient ischemic attacks, carotid \
endarterectomies are usually done for preventative healthcare.[1]\n\n\
Sources:\n\
[1]. https://en.wikipedia.org/wiki/Carotid_sinus"
  );

  auto icc_branches = std::make_shared<Menu>(
    "Internal Carotid Artery",
    std::vector<std::string>{
      "Carotid Sinus",
      "Carotid Body"
    },

    std::vector<std::function<void()>>{
      [carotid_sinus]{carotid_sinus->run();}
    },
    true
  );

  auto cca_branches = std::make_shared<Menu>(
    "Common Carotid Branches",
    std::vector<std::string>{
      "External Carotid",
      "Internal Carotid"
    },

    std::vector<std::function<void()>>{
      []{ print("hi\n"); },
      [icc_branches]{icc_branches->run();}
    },
    true
  );

  auto bct_branches = std::make_shared<Menu>(
    "Branches of the Brachiocephalic Trunk",
    std::vector<std::string>{
      "Right Common Carotid",
      "Right Subclavian"
    },

    std::vector<std::function<void()>>{
      [cca_branches]{cca_branches->run();},
      []{ print("coming soon\n"); }
    },
    true
  );

  auto submenu = std::make_shared<Menu>(
    "Artery Details",
    std::vector<std::string>{
      "Left Common Carotid",
      "Left Subclavian",
      "Brachiocephalic Trunk"
    },

    std::vector<std::function<void()>>{
      []{ print("Supplies left side of head/neck\n\nPress any key..."); },
      []{ print("Supplies left arm\n\nPress any key..."); },
      [bct_branches]{ bct_branches->run(); }
    },
    true
  );
  Menu main_menu(
    "Welcome to Arterypedia!\n",
    std::vector<std::string>{
      "View Aortic Arch Branches",
      "View Another System"
    },
    std::vector<std::function<void()>>{
      [submenu]{ submenu->run(); },
      []{ 
      clear(); 
      printw("More anatomy coming soon!\n\nPress any key...");
      refresh(); 
      getch(); 
      }
    }
  );

  main_menu.run();
  endwin();
  return 0;
}