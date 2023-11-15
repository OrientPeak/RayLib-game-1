#include "raylib.h"

class Background
{
    public:
        // init/assign textures
        Texture2D background = LoadTexture("resources/cyberpunk_street_background.png");
        Texture2D midground = LoadTexture("resources/cyberpunk_street_midground.png");
        Texture2D foreground = LoadTexture("resources/cyberpunk_street_foreground.png");

        //scrolling params
        float scrollingBack = 0.0f;
        float scrollingMid = 0.0f;
        float scrollingFront = 0.0f;

        void UpdateBackgrnd();
        void DrawBackgrnd(int screenWidth, int ScreenHeight);
        void BackgrndDein();
};