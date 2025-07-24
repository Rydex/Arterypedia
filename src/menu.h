#include <functional>
#include <vector>
#include <string>

class Menu {
private:
  std::string title, text, supply, branches, origin;
  std::vector<std::string> choices, related;
  bool is_submenu;
  std::vector<std::function<void()>> actions;
  int current_choice_index = 0;

  int text_start_ln = 0;
  int max_visible_ln = 0;

public:
  Menu(
    const std::string& title,
    const std::vector<std::string>& choices,
    const std::vector<std::function<void()>>& actions,
    bool is_submenu=false
  ) : title(title), choices(choices), is_submenu(is_submenu), actions(actions) {}

  Menu(
    const std::string& title,
    const std::string& text,
    const std::string& supply,
    const std::string& branches,
    const std::string& origin,
    const std::vector<std::string>& related
  ): title(title), text(text), supply(supply), branches(branches), origin(origin), choices(), related(related), is_submenu(true) {}

  Menu(
    const std::string& title,
    const std::string& text,
    const std::vector<std::string>& related
  ): title(title), text(text), choices(), related(related), is_submenu(true) {}

  Menu(
    const std::string& title,
    const std::vector<std::string>& choices,
    const std::vector<std::function<void()>>& actions,
    const std::string& text,
    bool is_submenu=false
  ): title(title), text(text), choices(choices), is_submenu(is_submenu), actions(actions) {}

  void show();
  void run();

  void scroll_text_up();
  void scroll_text_down();

  decltype(choices) get_choices() const;
};

void print(const std::string& text);