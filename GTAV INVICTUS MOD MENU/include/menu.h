#pragma once
#include <vector>
#include <string>

namespace Menu {
    void Initialize();
    void Update();
    void DrawMenu();

    extern bool menuOpen;
    extern int currentOption;
    extern int maxOptions;
    extern std::vector<std::string> options;
}
