#include <functional>
#include <vector>
#include <string>

class Menu {
private:
  std::string title, text;
  std::vector<std::string> choices, related;
  bool is_submenu;
  std::vector<std::function<void()>> actions;
  int current_choice_index = 0;

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
    const std::vector<std::string>& related
  ): title(title), text(text), choices(), related(related), is_submenu(true) {}

  Menu(
    const std::string& title,
    const std::vector<std::string>& choices,
    const std::vector<std::function<void()>>& actions,
    const std::string& text,
    bool is_submenu=false
  ): title(title), text(text), choices(choices), actions(actions), is_submenu(is_submenu) {}

  void show();
  void run();

  decltype(choices) get_choices() const;
};

void print(const std::string& text);