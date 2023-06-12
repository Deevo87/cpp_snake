//
// Created by rlaskowski on 11.06.23.
//

#ifndef CPP_PROJECT_SNAKE_SNAKE_H
#define CPP_PROJECT_SNAKE_SNAKE_H

#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>
#include <map>
#include <functional>
#include "Moves.h"

class Snake {
private:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Color darkGreen = {43, 51, 24, 255};
    Vector2 direction = {1, 0};
    double lastUpdateTime = 0;
    static std::map<Moves, std::function<void(Snake&)>> actions;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
public:
    void Draw(int cellSize);

    void Update();

    bool eventTriggered(double interval);

    void parse(Moves move);

    void move();
};


#endif //CPP_PROJECT_SNAKE_SNAKE_H
