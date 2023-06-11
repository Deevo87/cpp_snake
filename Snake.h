//
// Created by rlaskowski on 11.06.23.
//

#ifndef CPP_PROJECT_SNAKE_SNAKE_H
#define CPP_PROJECT_SNAKE_SNAKE_H

#include <iostream>
#include <raylib.h>
#include <deque>

class Snake {
private:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Color darkGreen = {43, 51, 24, 255};
public:
    void Draw(int cellSize);
};


#endif //CPP_PROJECT_SNAKE_SNAKE_H
