#include "menu.h"

int main() {
    Menu::Initialize();
    while (true) {
        Menu::Update();
        // Petite pause pour éviter de saturer le CPU
        // sleep(10); // À adapter selon ton environnement
    }
    return 0;
}