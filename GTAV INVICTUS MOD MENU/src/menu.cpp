#include "menu.h"
#include "drawing.h"
#include "natives.h"

bool Menu::menuOpen = false;
int Menu::currentOption = 0;
int Menu::maxOptions = 0;
std::vector<std::string> Menu::options;

namespace Menu {

    void Initialize() {
        options.clear();
        options.push_back("Self Options");
        options.push_back("Vehicle Spawner");
        options.push_back("Settings");

        maxOptions = options.size();
    }

    void DrawMenu() {
        // Header vert
        Drawing::DrawRect(0.5f, 0.1f, 0.3f, 0.06f, 0, 255, 0, 255);
        Drawing::DrawText(0.5f, 0.085f, "INVICTUS");

        // Options
        float y = 0.16f;
        for (int i = 0; i < maxOptions; i++) {
            if (i == currentOption) {
                Drawing::DrawRect(0.5f, y, 0.3f, 0.04f, 255, 255, 255, 255);
                Drawing::DrawText(0.5f, y - 0.015f, options[i].c_str());
            }
            else {
                Drawing::DrawRect(0.5f, y, 0.3f, 0.04f, 0, 0, 0, 150);
                Drawing::DrawText(0.5f, y - 0.015f, options[i].c_str());
            }
            y += 0.05f;
        }
    }

    void Update() {
        // Vérifie si la combinaison R1 + → est pressée pour ouvrir/fermer le menu
        if (PAD::IS_CONTROL_PRESSED(0, ControlFrontendRb) && PAD::IS_CONTROL_JUST_PRESSED(0, ControlFrontendRight)) {
            menuOpen = !menuOpen;
        }

        if (!menuOpen) return; // si menu fermé, rien à dessiner

        // Navigation ↑ ↓
        if (PAD::IS_CONTROL_JUST_PRESSED(0, ControlFrontendUp)) {
            currentOption--;
            if (currentOption < 0) currentOption = maxOptions - 1;
        }
        if (PAD::IS_CONTROL_JUST_PRESSED(0, ControlFrontendDown)) {
            currentOption++;
            if (currentOption >= maxOptions) currentOption = 0;
        }

        // Validation avec →
        if (PAD::IS_CONTROL_JUST_PRESSED(0, ControlFrontendRight)) {
            // Exemple d’action : toggle GodMode si premier menu
            if (currentOption == 0) {
                // Appel fonction godmode
            }
        }

        // Dessin du menu
        DrawMenu();
    }
}
