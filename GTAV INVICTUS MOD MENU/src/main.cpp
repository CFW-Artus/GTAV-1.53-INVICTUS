#include "menu.h"

int main() {
    Menu::Initialize();
    while (true) {
        Menu::Update();
        // Petite pause pour �viter de saturer le CPU
        // sleep(10); // � adapter selon ton environnement
    }
    return 0;
}