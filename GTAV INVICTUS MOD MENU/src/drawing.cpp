#include "drawing.h"

// � adapter selon ton framework graphique PS4
namespace Drawing {
    void DrawRect(float x, float y, float width, float height, int r, int g, int b, int a) {
        printf("DrawRect appel� : x=%f, y=%f, w=%f, h=%f, couleur=(%d,%d,%d,%d)\n", x, y, width, height, r, g, b, a);
    }

    void DrawText(float x, float y, const char* text) {
        // Appel � ta fonction native de dessin de texte
    }
}