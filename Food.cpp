//
// Created by rlaskowski on 11.06.23.
//

#include "Food.h"


Food::Food(int cellCount) {
    Image image = LoadImage("../resources/redApple.png");
    this->texture = LoadTextureFromImage(image);
    UnloadImage(image);
    this->position = generateRandomPos(cellCount);
}

Food::~Food() {
    UnloadTexture(texture);
}

Vector2 Food::getPosition() const {
    return this->position;
}

void Food::Draw(int cellSize) {
    DrawTexture(texture, this->position.x * cellSize, this->position.y * cellSize, WHITE);
}

Vector2 Food::generateRandomPos(int cellCount) {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

void Food::setPosition(Vector2 newPosition) {
    this->position = newPosition;
}


