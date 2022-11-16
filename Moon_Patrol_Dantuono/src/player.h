#pragma once
#include "timer.h"
#include "obstacle.h"
#include "shoot.h"

class Player {
private:
	float x;
	float y;

	float floorY;

	Vector2 velocity;
	float AlternVelocity;
	float gravity;
	float width;
	float height;
	
	bool jump;
	Rectangle colision;

	Shoot* shoot;
	Obstacle* object;
	Obstacle* flyObject;

public:
	Player(float x, float y, float velocityX, float velocityY, float gravity, float width, float height);
	void DrawPlayer();
	void MovePlayer();
	bool CheckColision();
	void RestartPlayer();
	float GetXVelocity();
	float GetX();
	float GetY();
};

static int jumpTimer = 0;

	

