/*___________________________________________/
/ background animation                       /
/ taken from                                 /
/ https://www.raylib.com/examples.html       /
/ Obstacle Manager                           /
/ taken from                                 /
/ https://github.com/euiko/raylib-flappybird /
/___________________________________________*/



#include "raylib.h"
#include "Background.h"
#include "ObstacleManager.h"
#include "Player.h"

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

    Image obstacleImage = LoadImage("resources/pipe-green.png");

    Image baseImage = LoadImage("resources/base.png");
    Texture2D baseTexture = LoadTextureFromImage(baseImage);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

   float speed = 300;


    float currentBasePosition = 0;
   // Vector2 characterPosition = Vector2{60, (float)screenHeight/2};
     ObstacleManager obstacleManager(obstacleImage, speed, (Vector2){(float)screenWidth,(float)(screenHeight-baseTexture.height)}, 500);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //updating the background by calling the update functions from the background .cpp/.h
        background.UpdateBackgrnd();
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //draw background
            background.DrawBackgrnd(screenWidth, screenHeight);

            float frameSpeed = GetFrameTime() * speed;
            obstacleManager.setSpeed(frameSpeed);
            DrawFPS(500, 500);
            obstacleManager.generateObstacle(currentBasePosition);
            obstacleManager.drawObstacles();
            currentBasePosition += frameSpeed;

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    background.BackgrndDein();
    UnloadImage(baseImage);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}