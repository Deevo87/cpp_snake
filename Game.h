//
// Created by rlaskowski on 12.06.23.
//

#ifndef CPP_PROJECT_SNAKE_GAME_H
#define CPP_PROJECT_SNAKE_GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
private:
    int cellSize = 30;
    int cellCount = 25;
public:
    Snake snake = Snake();
    Food food = Food(cellCount);

    void Draw();

    void Update();

    void eatFood();

    bool elementInBody(Vector2 element);
};


#endif //CPP_PROJECT_SNAKE_GAME_H
