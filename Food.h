//
// Created by rlaskowski on 11.06.23.
//

#ifndef CPP_PROJECT_SNAKE_FOOD_H
#define CPP_PROJECT_SNAKE_FOOD_H

#include <iostream>
#include <raylib.h>


class Food {
private:
    Vector2 position{};
    Texture2D texture{};
public:
    explicit Food(int cellCount);

    ~Food();

    [[nodiscard]] Vector2 getPosition() const;

    void setPosition(Vector2 newPosition);

    void Draw(int cellSize);

    static Vector2 generateRandomPos(int cellCount);
};


#endif //CPP_PROJECT_SNAKE_FOOD_H
