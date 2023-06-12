#include <iostream>
#include <raylib.h>
#include "Food.h"
#include "Snake.h"

using namespace std;

Color green = {173, 204, 96, 255};

int cellSize = 30;
int cellCount = 25;


int main() {

    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Food food = Food(cellCount);
    Snake snake = Snake();

    while (!WindowShouldClose()) {
        BeginDrawing();

        //Updating snake position
        if (snake.eventTriggered(0.2)) {
            snake.Update();
        }
        snake.move();

        //Drawing
        ClearBackground(green);
        food.Draw(cellSize);
        snake.Draw(cellSize);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}