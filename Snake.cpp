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
    body.push_front(Vector2Add(body[0], this->direction));
    if (this->addSegment) {
        this->addSegment = false;
    } else {
        body.pop_back();
    }
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

bool Snake::move() {
    if (IsKeyPressed(KEY_UP) && this->direction.y != 1) {
        parse(UP);
    } else if (IsKeyPressed(KEY_DOWN) && this->direction.y != -1) {
        parse(DOWN);
    } else if (IsKeyPressed(KEY_LEFT) && this->direction.x != 1) {
        parse(LEFT);
    } else if (IsKeyPressed(KEY_RIGHT) && this->direction.x != -1) {
        parse(RIGHT);
    } else {
        return false;
    }
    return true;
}

bool Snake::eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

std::deque<Vector2> Snake::getSnakeBody() const {
    return this->body;
}

bool Snake::ifAddSegment() const {
    return this->addSegment;
}

void Snake::setAddSegment(bool ifSegment) {
    this->addSegment = ifSegment;
}

void Snake::reset() {
    this->body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    this->direction = {1, 0};
}
