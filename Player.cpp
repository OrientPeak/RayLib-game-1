#include "Player.h"
#include "Timer.h"

void Player::UpdatePlayer(int screenHeight)
{
    //if space pressed stop downward momentum and go up based on the multiplier
    if(IsKeyPressed(KEY_SPACE) && birdVelocity >= gravity / 3.0f)
    {
        float jump = 5.0f * multiplier;

        birdAcceleration = 0.0f;
        birdVelocity = -(gravity * 5) * jump;
        PlaySound(wingFlap);
    }
    //else continue with downward speed
    else
    {
        birdAcceleration += gravity * 0.1f;
    }
    //stop speed from increasing infinitely
    if(birdAcceleration >= gravity)
    {
        birdAcceleration = gravity;
    }
    //set bird acceleration and position
    birdVelocity += birdAcceleration * 0.1f;
    birdPosition += birdVelocity * 0.1f;

    if(birdPosition >= 720)
    {
        birdPosition = screenHeight;
    }
    else if (birdPosition <= 20)
    {
        birdPosition = 20;
    }
}

void Player::DrawPlayer(int screenWidth)
{
    //calculate bird x position
    birdX = (int)(screenWidth / 3.0f);
    //depending on velocity draw bird with wings up or down
    if(birdVelocity >= 0)
    {
        DrawTextureEx(playerUp, (Vector2){birdX, birdPosition }, 0.0f, 3.0f, WHITE);
    }
    else
    {
        DrawTextureEx(playerDown, (Vector2){birdX, birdPosition }, 0.0f, 3.0f, WHITE);
    }
}

void Player::PlayerDein()
{
    UnloadTexture(playerDown);
    UnloadTexture(playerUp);
}

void Player::setMulti(float multi)
{
    multi = multiplier;
}