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
    void LogicShoot1();
    void LogicShoot2();
    float GetX();
    float GetY();
    float GetRadius();
    void ActiveFalse();
    bool IsActive();
    void DrawBullet();
};
