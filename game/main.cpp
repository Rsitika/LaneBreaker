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

const int TOTAL_CARS = 3;
int carLane[TOTAL_CARS];
int carY[TOTAL_CARS];

for (int i = 0; i < TOTAL_CARS; i++)
{
    carLane[i] = rand() % 3;
    carY[i] = -(i * 250);
}

    bool gameOver = false;

    int score = 0;

    int highScore = 0;

    int carSpeed = 4;

    int roadOffset = 0;

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
 for (int i = 0; i < TOTAL_CARS; i++){
    carY[i] += carSpeed;

    if (carY[i] > 600){
        score++;

        if (score > highScore){
            highScore = score;
        }

        if (score >= 20)
{
    carSpeed = 8;
}
else if (score >= 15)
{
    carSpeed = 7;
}
else if (score >= 10)
{
    carSpeed = 6;
}
else if (score >= 5)
{
    carSpeed = 5;
}
else
{
    carSpeed = 4;
}

        carY[i] = -(rand() % 300 + 100);
        carLane[i] = rand() % 3;


    }
}
roadOffset += carSpeed;
if (roadOffset >= 60){
    roadOffset = 0;
}
}



if (gameOver && IsKeyPressed(KEY_R))
{
    gameOver = false;

    currentLane = 1;
    bikeY = 500;
       score = 0;

   for (int i = 0; i < TOTAL_CARS; i++){
    carLane[i] = rand() % 3;
    carY[i] = -(i * 250);
}
 
}

Rectangle bikeRect =
{
    (float)laneX[currentLane],
    (float)bikeY,
    40,
    70
};


BeginDrawing();

        ClearBackground(GREEN);

        DrawRectangle(100, 0, 600, 600, DARKGRAY);

        // Lane Divider 1
        for (int y = 0; y < 600; y += 60) {
            DrawRectangle(295, y + roadOffset, 10, 35, WHITE);
        }

        // Lane Divider 2
        for (int y = 0; y < 600; y += 60){
            DrawRectangle(495, y + roadOffset, 10, 35, WHITE);
        }

        // Car
        for (int i = 0; i < TOTAL_CARS; i++){
    DrawRectangle(laneX[carLane[i]], carY[i], 40, 80, RED);
}
      for (int i = 0; i < TOTAL_CARS; i++)
{
    Rectangle carRect =
    {
        (float)laneX[carLane[i]],
        (float)carY[i],
        40,
        80
    };

    if (CheckCollisionRecs(bikeRect, carRect))
    {
        gameOver = true;
        break;
    }
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
        
         DrawText(TextFormat("Speed : %i", carSpeed),
         20,
         120,
         25,
         ORANGE);
     
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