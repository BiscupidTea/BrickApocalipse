#pragma once

#include "raylib.h"

class Obstacle {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;

	Rectangle colision;

public:
	Obstacle(float x, float y, float velocity, float width, float height);
	void DrawObstacle();
	void MoveObstacle();
	float GetX();
	float GetY();
	float GetWidht();
	float GetHeight();
	void RestartPosition();
	void RestartObstacle();
};
