#pragma once

#include "raylib.h"
#include "Player.h"


class Timer
{
public:

    Player* player;

    int multiTime;
    float time = 1.5f;
    int frames = 0;

    int pUpFrames = 0;
    float pUpTime = 30.0f;
    bool powerUp = false;

    void Time();
    void Print(float score);
};