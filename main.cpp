#include <iostream>
#include <raylib.h>
#include "Game.h"

using namespace std;

Color green = {128, 215, 100, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 70;

int main() {

    cout << "Starting the game..." << endl;
    InitWindow(cellSize * cellCount + 2 * offset, cellSize * cellCount + 2 * offset, "Snake");
    SetTargetFPS(60);

    Game game = Game(cellSize, cellCount, offset);

    while (!WindowShouldClose()) {
        BeginDrawing();

        //Updating snake position
        if (game.snake.eventTriggered(0.2)) {
            game.Update();
        }

        if (game.snake.move()) game.setRunning(true);

        //Drawing
        ClearBackground(green);
        DrawRectangleLinesEx(
                Rectangle{(float) offset - 5, (float) offset - 5, (float) cellSize * (float) cellCount + 10,
                          (float) cellSize * (float) cellCount + 10}, 5, darkGreen);
        DrawText(TextFormat("%i", game.getScore()), (cellSize * cellCount) / 2 + offset, cellCount / 2 + 5, 40, BLACK);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}