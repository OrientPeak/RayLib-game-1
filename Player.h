#pragma once

#include "raylib.h"

class Player
{
    public:
        //textures
        Texture2D playerDown = LoadTexture("resources/bluebird-downflap.png");
        Texture2D playerUp = LoadTexture("resources/bluebird-upflap.png");

        //player variables
        float birdAcceleration = 0.0f;
        float birdVelocity = 0.0f;
        float birdPosition = 0.0f;

        float gravity = 50.0f;

        //player functions
        void UpdatePlayer();
        void DrawPlayer(const int screenWidth);
        void PlayerDein();
};