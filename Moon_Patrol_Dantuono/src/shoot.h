#pragma once
#include "raylib.h"

class Shoot {
private:
    Vector2 position;
    float speed;
    float radius;
    bool active;

public:
    Shoot(Vector2 position, float speed, float radius);
    void GetPosition(float x, float y);
    void LogicShoot();
    bool isActive();
};
