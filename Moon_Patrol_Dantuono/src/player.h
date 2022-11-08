#pragma once
#include "obstacle.h"
#include "shoot.h"

class Player {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;
	
	bool jump;
	Rectangle colision;

	Shoot* shoot;
	Obstacle* object;

public:
	Player(float x, float y, float velocity, float width, float height);
	void DrawPlayer();
	void MovePlayer();
	bool CheckColision();
	void RestartPlayer();
	float GetXVelocity();
	float GetX();
	float GetY();
};

static int jumpTimer = 0;

	

