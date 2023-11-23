#include "Player.h"

void Player::UpdatePlayer()
{
    //if space pressed stop downward momentum and swap to up
    if(IsKeyPressed(KEY_SPACE))
    {
        birdAcceleration = 0.0f;
        birdVelocity = -gravity / 0.5f;
    }
    //ekse continue with downward speed
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
}

void Player::DrawPlayer(int screenWidth)
{
    //calculate bird x position
    int birdX = (int)(screenWidth / 3.0f);
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