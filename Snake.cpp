//
// Created by rlaskowski on 11.06.23.
//

#include "Snake.h"

void Snake::Draw(int cellSize) {
    for(unsigned int i = 0; i < this->body.size(); i++) {
        int x = body[i].x;
        int y = body[i].y;
        DrawRectangle(x * cellSize, y * cellSize, cellSize, cellSize, darkGreen);
    }
}
