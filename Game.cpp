//
// Created by rlaskowski on 12.06.23.
//

#include "Game.h"

Game::Game(int cellSize, int cellCount) : cellSize(cellSize), cellCount(cellCount) {

}

void Game::Draw() {
    if (running) {
        food.Draw(cellSize);
        snake.Draw(cellSize);
    } else {
        food.Draw(cellSize);
        snake.Draw(cellSize);
        const char *message = "GAME OVER";
        int fontSize = 60;
        int padding = 10;
        int textWidth = MeasureText(message, fontSize);
        int reactX = (cellCount * cellSize - textWidth) / 2 - padding;
        int reactY = (cellCount * cellSize - fontSize) / 2 - padding;
        int reactWidth = textWidth + padding * 2;
        int reactHeight = fontSize + padding * 2;

        DrawRectangle(reactX, reactY, reactWidth, reactHeight, BLACK);
        DrawText(message, reactX + padding, reactY + padding, fontSize, WHITE);
    }
}

void Game::Update() {
    if (running) {
        snake.Update();
        eatFood();
        checkCollisionsWithBorders();
        checkCollisionsWithBody();
    }
}

void Game::eatFood() {
    if (Vector2Equals(snake.getSnakeBody()[0], food.getPosition())) {
        Vector2 randomPos = Food::generateRandomPos(cellCount);
        while (elementInBody(randomPos, this->snake.getSnakeBody())) {
            randomPos = Food::generateRandomPos(cellCount);
        }
        this->snake.setAddSegment(true);
        food.setPosition(randomPos);
    }
}

bool Game::elementInBody(Vector2 element, const std::deque<Vector2> &body) const {
    for (auto i: body) {
        if (Vector2Equals(i, element)) {
            return true;
        }
    }
    return false;
}

void Game::checkCollisionsWithBorders() {
    std::deque<Vector2> body = this->snake.getSnakeBody();
    if (body[0].x == cellCount || body[0].x == -1 || body[0].y == cellCount || body[0].y == -1) {
        gameOver();
    }
}

void Game::checkCollisionsWithBody() {
    std::deque<Vector2> headless = this->snake.getSnakeBody();
    headless.pop_front();
    if (elementInBody(this->snake.getSnakeBody()[0], headless)) {
        gameOver();
    }
}

void Game::gameOver() {
    this->snake.reset();
    this->food.setPosition(Food::generateRandomPos(cellCount));

    this->running = false;
}

bool Game::ifRunning() const {
    return this->running;
}

void Game::setRunning(bool isRunning) {
    this->running = isRunning;
}