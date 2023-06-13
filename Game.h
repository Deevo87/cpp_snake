#ifndef CPP_PROJECT_SNAKE_GAME_H
#define CPP_PROJECT_SNAKE_GAME_H

#include "Snake.h"
#include "Food.h"
#include <raylib.h>

class Game {
private:
    int cellSize;
    int cellCount;
    int offset;
    bool running = true;
    int score = 0;
public:
    Game(int cellSize, int cellCount, int offset);

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

    void setScore(int newScore);

    [[nodiscard]] int getScore() const;
};


#endif //CPP_PROJECT_SNAKE_GAME_H
