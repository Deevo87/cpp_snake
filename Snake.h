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
    bool addSegment = false;
    double lastUpdateTime = 0;
    static std::map<Moves, std::function<void(Snake&)>> actions;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
public:
    void Draw(int cellSize, int offset);

    void Update();

    void parse(Moves move);

    bool move();

    bool eventTriggered(double interval);

    [[nodiscard]] std::deque<Vector2> getSnakeBody() const;

    [[nodiscard]] bool ifAddSegment() const;

    void setAddSegment(bool ifSegment);

    void reset();
};


#endif //CPP_PROJECT_SNAKE_SNAKE_H
