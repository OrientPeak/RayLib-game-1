#include "Timer.h"

void Timer::Print(float score)
{
    DrawText(TextFormat("Score: %d", (int)score), 10, 10, 24, RED);
    DrawText(TextFormat("Timer: %.1f", (float)time), 10, 40, 24, RED);
}

void Timer::Time()
{
    frames++;
    if(frames >= 6)
    {
        time -= 0.1f;
        frames = 0;
    }
    if(IsKeyPressed(KEY_SPACE))
    {
        time = 1.5f;
    }

    switch((int)(time * 10))
    {
        case 0:
            player.setMulti(1.0f);
            break;
        case 1:
        case -1:
            player.setMulti(0.9f);
            break;
        case 2 ... 4:
        case -4 ... -2:
            player.setMulti(0.5f);
            break;
        case 5 ... 8:
        case -8 ... -5:
            player.setMulti(0.2f);
            break;
        default:
            player.setMulti(0.0f);
            break;

    }    
}