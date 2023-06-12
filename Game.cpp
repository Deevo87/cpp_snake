//
// Created by rlaskowski on 12.06.23.
//

#include "Game.h"

void Game::Draw() {
    food.Draw(cellSize);
    snake.Draw(cellSize);
}

void Game::Update() {
    snake.Update();
    eatFood();
}

void Game::eatFood() {
    if (Vector2Equals(snake.getSnakeBody()[0], food.getPosition())) {
        Vector2 randomPos = Food::generateRandomPos(cellCount);
        while (elementInBody(randomPos)) {
            randomPos = Food::generateRandomPos(cellCount);
        }
        std::cout << "eating food at position: " << food.getPosition().x << food.getPosition().y << std::endl;
        food.setPosition(randomPos);
    }
}

bool Game::elementInBody(Vector2 element) {
    std::deque<Vector2> body = this->snake.getSnakeBody();
    for (auto i : body) {
        if (Vector2Equals(i, element)) {
            return true;
        }
    }
    return false;
}
