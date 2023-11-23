/*___________________________________________________________________________________________________________________/
/ background animation                                                                                               /
/ taken from                                                                                                         /
/ https://www.raylib.com/examples.html                                                                               /
/ Player                                                                                                             /
/ taken from                                                                                                         /
/ https://youtu.be/b6A4XHkTjs8                                                                                       / 
/___________________________________________________________________________________________________________________*/



#include "raylib.h"
#include "Background.h"
#include "Player.h"
#include "Timer.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Floopy Dood");

    Background background;
    Player player;
    Timer timer;

    InitAudioDevice();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
     
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //updating the background
        background.UpdateBackgrnd();
        //update the player 
        player.UpdatePlayer(screenHeight);
        
        float score = GetTime();

        timer.Time();
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //draw background
            background.DrawBackgrnd(screenWidth, screenHeight);
            //draw player
            player.DrawPlayer(screenWidth);

            timer.Print(score);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    background.BackgrndDein();
    player.PlayerDein();
    CloseAudioDevice();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}