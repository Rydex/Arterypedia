#include <functional>
#include <ncurses/curses.h>
#include <string>
#include <memory>
#include "menu.h"

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