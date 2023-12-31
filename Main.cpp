/*_______________________________________/
/ background animation                   /
/ taken from                             /
/ https://www.raylib.com/examples.html   /
/ Player                                 /
/ taken from                             /
/ https://youtu.be/b6A4XHkTjs8           / 
/_______________________________________*/

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

    InitAudioDevice();

    Background background;
    Player player;
    Timer timer;

    timer.player = &player;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
     
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //updating the background
        background.UpdateBackgrnd();

        float score /*= GetTime()*/;

        if(player.alive == true)
            score = GetTime();

        timer.Time();

        //update the player 
        player.UpdatePlayer(screenHeight);

        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            //check if player alive
            if(player.alive == true)
            {
                //draw background
                background.DrawBackgrnd(screenWidth, screenHeight);
                //draw player
                player.DrawPlayer(screenWidth);

                timer.Print(score);

            }
            else
            {
                //end screen text
                DrawText(TextFormat("GAME OVER \nPress SPACE to EXIT"), screenWidth/3, 200, 60, RED);
                DrawText(TextFormat("Final Score: %d", (int)score), screenWidth/3, 370, 40, RED);
                SetExitKey(KEY_SPACE);
                
            }

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