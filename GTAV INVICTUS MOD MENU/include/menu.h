#pragma once

class Menu {
public:
    void run();
    bool menuOpen = false;
    bool godModeEnabled = false;
    int selectedIndex = 0;
    void drawMenu();
    void handleInput();
};

// Fonctions d'input réelles
bool IsButtonPressed(int button);
bool IsButtonJustPressed(int button);
enum PadButton {
    PAD_UP = 0,
    PAD_DOWN,
    PAD_LEFT,
    PAD_RIGHT,
    PAD_CROSS,
    PAD_CIRCLE,
    PAD_R1
};