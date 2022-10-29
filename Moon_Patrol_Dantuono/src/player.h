#pragma once
#include "obstacle.h"

class Player {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;

	Rectangle colision;

	Obstacle* object;

public:
	Player(float x, float y, float velocity, float width, float height);
	void DrawPlayer();
	void MovePlayer();
	void CheckColision();
};


	

