#include "Timer.h"

void Timer::Print(float score)
{
    DrawText(TextFormat("Score: %d", (int)score), 10, 10, 24, RED);
    DrawText(TextFormat("Timer: %.1f", (float)time), 60, 10, 24, RED);
    DrawText(TextFormat("PowerUp: %.1f", (float)pUpTime), 10, 50, 24, RED);
}

void Timer::Time()
{
    frames++;
    if(frames >= 6)
    {
        time -= 0.1f;
        frames = 0;
    }

    pUpFrames++;
    if(frames >= 6)
    {
        pUptime -= 0.1f;
        frames = 0;
    }

    if(pUpTime <= 0)
    {
        powerUp = true;
    }
    
    if(IsKeyPressed(KEY_SPACE))
    {
        if(powerUp = true)
        {
            player->setMulti(2.0f);
            powerUp == false;
            pUpTime = 30.0f
        }
        else
        {
        switch(multiTime)
        {
            case 0:
                player->setMulti(1.0f);
                break;
            case 1:
            case -1:
                player->setMulti(0.9f);
                break;
            case 2 ... 4:
            case -4 ... -2:
                player->setMulti(0.5f);
                break;
            case 5 ... 8:
            case -8 ... -5:
                player->setMulti(0.2f);
                break; 
            default:
                player->setMulti(0.0f);
                break;
        }  
        }
  
        time = 1.5f;
    }
    
    multiTime = (int)(time * 10);
}