#include <iostream>
#include <raylib.h>
#include "Game.h"

using namespace std;

Color green = {173, 204, 96, 255};

int cellSize = 30;
int cellCount = 25;


int main() {

    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Snake");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        BeginDrawing();

        //Updating snake position
        if (game.snake.eventTriggered(0.2)) {
            game.Update();
        }

        if (game.snake.move()) game.setRunning(true);

        //Drawing
        ClearBackground(green);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}