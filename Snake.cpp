//
// Created by rlaskowski on 11.06.23.
//

#include "Snake.h"


void Snake::Draw(int cellSize) {
    for (unsigned int i = 0; i < this->body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{x * (float) cellSize, y * (float) cellSize, float(cellSize), float(cellSize)};
        DrawRectangleRounded(segment, 0.5, 6, this->darkGreen);
    }
}

void Snake::Update() {
    body.pop_back();
    body.push_front(Vector2Add(body[0], this->direction));
}

bool Snake::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void Snake::parse(Moves move) {
    if (actions.find(move) != actions.end()) {
        actions.at(move)(*this);
    }
}

std::map<Moves, std::function<void(Snake &)>> Snake::actions = {
        {UP,    &Snake::moveUp},
        {DOWN,  &Snake::moveDown},
        {LEFT,  &Snake::moveLeft},
        {RIGHT, &Snake::moveRight}
};

void Snake::moveUp() {
    this->direction = {0, -1};
}

void Snake::moveDown() {
    this->direction = {0, 1};
}

void Snake::moveLeft() {
    this->direction = {-1, 0};
}

void Snake::moveRight() {
    this->direction = {1, 0};
}

void Snake::move() {
    if (IsKeyPressed(KEY_UP) && this->direction.y != 1) {
        parse(UP);
    } else if (IsKeyPressed(KEY_DOWN) && this->direction.y != -1) {
        parse(DOWN);
    } else if (IsKeyPressed(KEY_LEFT) && this->direction.x != 1) {
        parse(LEFT);
    } else if (IsKeyPressed(KEY_RIGHT) && this->direction.x != -1) {
        parse(RIGHT);
    }
}
