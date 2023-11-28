#pragma once

#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

class Player
{
    public:

        //textures
        Texture2D playerDown = LoadTexture("resources/bluebird-downflap.png");
        Texture2D playerUp = LoadTexture("resources/bluebird-upflap.png");
        //sound
        Sound wingFlap = LoadSound("resources/flap.wav");

        Rectangle rect; //collider

        //player variables
        float birdAcceleration = 0.0f;
        float birdVelocity = 0.0f;
        float birdPosition = 0.0f;

        float multiplier = 0;

        float miss;

        int birdX;

        float gravity = 1.0f;

        //player functions
        void UpdatePlayer(int screenHeight);
        void DrawPlayer(const int screenWidth);
        void PlayerDein();

        void setMulti(float multi);
};