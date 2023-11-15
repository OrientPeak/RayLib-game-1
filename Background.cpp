#include "Background.h"

void Background::UpdateBackgrnd()
{
    //scrolling speed update
    scrollingBack -= 0.1f;
    scrollingMid -= 0.5f;
    scrollingFront -= 1.0f;

    // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
    if (scrollingBack <= -background.width*2) scrollingBack = 0;
    if (scrollingMid <= -midground.width*2) scrollingMid = 0;
    if (scrollingFront <= -foreground.width*2) scrollingFront = 0;
}

void Background::DrawBackgrnd(int screenWidth, int screenHeight)
{
    // Draw background image twice
    // NOTE: Texture is scaled three and a half times its size
    DrawTextureEx(background, (Vector2){ scrollingBack, 20 }, 0.0f, 3.5f, WHITE);
    DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 20 }, 0.0f, 3.5f, WHITE);

    // Draw midground image twice
    DrawTextureEx(midground, (Vector2){ scrollingMid, 20 }, 0.0f, 3.5f, WHITE);
    DrawTextureEx(midground, (Vector2){ midground.width*2 + scrollingMid, 20 }, 0.0f, 3.5f, WHITE);

    // Draw foreground image twice
    DrawTextureEx(foreground, (Vector2){ scrollingFront, 70 }, 0.0f, 3.5f, WHITE);
    DrawTextureEx(foreground, (Vector2){ foreground.width*2 + scrollingFront, 70 }, 0.0f, 3.5f, WHITE);
}

void Background::BackgrndDein()
{
    UnloadTexture(background);  // Unload background texture
    UnloadTexture(midground);   // Unload midground texture
    UnloadTexture(foreground);  // Unload foreground texture
}