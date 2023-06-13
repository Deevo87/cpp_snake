//
// Created by rlaskowski on 12.06.23.
//

#ifndef CPP_PROJECT_SNAKE_GAME_H
#define CPP_PROJECT_SNAKE_GAME_H

#include "Snake.h"
#include "Food.h"
#include <raylib.h>

class Game {
private:
    int cellSize;
    int cellCount;
    bool running = true;
public:
    Game(int cellSize, int cellCount);

    Snake snake = Snake();
    Food food = Food(cellCount);

    void Draw();

    void Update();

    void eatFood();

    [[nodiscard]] bool elementInBody(Vector2 element, const std::deque<Vector2>& body) const;

    void checkCollisionsWithBorders();

    void checkCollisionsWithBody();

    void gameOver();

    [[nodiscard]] bool ifRunning() const;

    void setRunning(bool isRunning);

};


#endif //CPP_PROJECT_SNAKE_GAME_H
