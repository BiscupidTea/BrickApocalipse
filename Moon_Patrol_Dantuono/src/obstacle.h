#pragma once

#include "raylib.h"

class Obstacle {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;

	int timer = 0;
	Rectangle colision;

public:
	Obstacle(float x, float y, float velocity, float width, float height);
	void DrawObstacle();
	void MoveObstacle();
	void MoveFlyObstacle();
	float GetX();
	float GetY();
	float GetWidht();
	float GetHeight();
	void RestartPosition();
	void RestartFlyPosition();
	void RestartObstacle();
};
