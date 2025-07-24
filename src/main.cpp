#include <functional>
#include <ncurses/curses.h>
#include <string>
#include <memory>
#include "menu.h"

//forward declarations

std::shared_ptr<Menu> make_cs();
std::shared_ptr<Menu> make_cca();

//end

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);

  auto bct_branches = std::make_shared<Menu>(
    "Branches of the brachiocephalic trunk",
    std::vector<std::string>{
      "Right common carotid",
      "Right subclavian"
    },

    std::vector<std::function<void()>>{
      []{ make_cca()->run(); },
      []{ print("coming soon\n"); }
    },
    true
  );

  auto submenu = std::make_shared<Menu>(
    "Artery details",
    std::vector<std::string>{
      "Left common carotid",
      "Left subclavian",
      "Brachiocephalic trunk"
    },

    std::vector<std::function<void()>>{
      []{ print("This artery is usually symmetrical with the Right common carotid. See left common carotid"); },
      []{ print("This artery is usually symmetrical with the Right subclavian. See left subclavian"); },
      [bct_branches]{ bct_branches->run(); }
    },
    true
  );
  Menu main_menu(
    "Welcome to Arterypedia!\nNote: It is recommended that you zoom out of your console, as \
some descriptions can be very long.\n",
    std::vector<std::string>{
      "View aortic arch branches",
    },
    std::vector<std::function<void()>>{
      [submenu]{ submenu->run(); }
    }
  );

  main_menu.run();
  endwin();
  return 0;
}