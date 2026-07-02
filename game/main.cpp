#include "raylib.h"
#include <cstdlib>
#include <ctime>
int main()
{
    InitWindow(800, 600, "LaneBreaker");
    SetTargetFPS(60);
    srand(time(NULL));

    int currentLane = 1;
    int bikeY = 500;

    int carLane = 0;
    int carY = -100;

    bool gameOver = false;

    int laneX[3] = {180, 380, 580};

    while (!WindowShouldClose())
    {
        // Bike Movement
        if (!gameOver){
  
        if (IsKeyPressed(KEY_LEFT))
        {
            if (currentLane > 0)
            {
                currentLane--;
            }
        }

        if (IsKeyPressed(KEY_RIGHT))
        {
            if (currentLane < 2)
            {
                currentLane++;
            }
        }
    }

    if (!gameOver){
 // Car Movement
        carY += 4;

        // Respawn
       if (carY > 600){
    carY = -100;
    carLane = rand() % 3;
}
}

if (gameOver && IsKeyPressed(KEY_R))
{
    gameOver = false;

    currentLane = 1;
    bikeY = 500;

    carY = -100;
    carLane = rand() % 3;
}

Rectangle bikeRect =
{
    (float)laneX[currentLane],
    (float)bikeY,
    40,
    70
};

Rectangle carRect =
{
    (float)laneX[carLane],
    (float)carY,
    40,
    80
};

        BeginDrawing();

        ClearBackground(GREEN);

        DrawRectangle(100, 0, 600, 600, DARKGRAY);

        // Lane Divider 1
        for (int y = 0; y < 600; y += 60)
        {
            DrawRectangle(295, y, 10, 35, WHITE);
        }

        // Lane Divider 2
        for (int y = 0; y < 600; y += 60)
        {
            DrawRectangle(495, y, 10, 35, WHITE);
        }

        // Car
        DrawRectangle(laneX[carLane], carY, 40, 80, RED);
       
       if (CheckCollisionRecs(bikeRect, carRect)){
    gameOver = true;
}

        // Bike
        DrawRectangle(laneX[currentLane], bikeY, 40, 70, YELLOW);

        DrawText("LaneBreaker", 20, 20, 30, WHITE);

        if (gameOver){
    DrawText("GAME OVER", 220, 250, 50, RED);
    DrawText("Press R to Restart", 220, 320, 25, WHITE);
}



        EndDrawing();
    }

    CloseWindow();

    return 0;
}