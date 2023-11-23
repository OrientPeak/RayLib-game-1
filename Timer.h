#pragma once

#include "raylib.h"
#include "Player.h"

Player player;

class Timer
{
public:

    float time = 1.5f;
    int frames;

    void Time();
    void Print(float score);
};