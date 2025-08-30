#pragma once

namespace Drawing {
    void DrawRect(float x, float y, float width, float height, int r, int g, int b, int a);
    void DrawText(float x, float y, const char* text);
    void DrawSprite(const char* textureDict, const char* textureName, float x, float y, float width, float height, float heading, int r, int g, int b, int a);
    void DrawHeader(float x, float y, float width, float height, const char* text, int r, int g, int b, int a);
    void DrawOption(float x, float y, float width, float height, const char* text, bool selected);
    void DrawStatusText(float x, float y, const char* text, int r, int g, int b, int a);
}