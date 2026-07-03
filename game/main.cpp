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

    int score = 0;

    int highScore = 0;

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
         score++;
         if(score > highScore)
    {
        highScore = score;
    }
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
    score = 0;
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

       DrawText("LaneBreaker", 300, 20, 30, WHITE);
       DrawText(TextFormat("Score : %i", score), 620, 20, 25, WHITE);
       DrawText(TextFormat("High Score : %i", highScore),
         20,
         90,
         25,
         YELLOW);
     
       if (gameOver){
    DrawText("GAME OVER", 220, 220, 50, RED);

    DrawText(TextFormat("Final Score : %i", score), 220, 290, 30, YELLOW);

    DrawText("Press R to Restart", 220, 340, 25, WHITE);
}




        EndDrawing();
    }

    CloseWindow();

    return 0;
}