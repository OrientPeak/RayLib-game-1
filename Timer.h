#pragma once

#include "raylib.h"
#include "Player.h"


class Timer
{
public:

    Player player;

    int multiTime;
    float time = 1.5f;
    int frames;

    void Time();
    void Print(float score);
};