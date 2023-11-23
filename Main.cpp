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
    Player player;

    Image obstacleImage = LoadImage("resources/pipe-green.png");

    Image baseImage = LoadImage("resources/base.png");
    //Texture2D baseTexture = LoadTextureFromImage(baseImage);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

   float speed = 300;


    float currentBasePosition = 0;
   // Vector2 characterPosition = Vector2{60, (float)screenHeight/2};
     ObstacleManager obstacleManager(obstacleImage, speed, (Vector2){(float)screenWidth,(float)(screenHeight/*-baseTexture.height*/)}, 500);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //updating the background by calling the update functions from the background .cpp/.h
        background.UpdateBackgrnd();
        player.UpdatePlayer();
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //draw background
            background.DrawBackgrnd(screenWidth, screenHeight);
            player.DrawPlayer(screenWidth);

            float frameSpeed = GetFrameTime() * speed;
            obstacleManager.setSpeed(frameSpeed);
            obstacleManager.generateObstacle(currentBasePosition);
            obstacleManager.drawObstacles();
            currentBasePosition += frameSpeed;

            //DrawTextureEx(baseTexture, (Vector2){(float)screenWidth, (float)200.0f}, 0.0f, 1.0f, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    background.BackgrndDein();
    player.PlayerDein();
    UnloadImage(baseImage);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}