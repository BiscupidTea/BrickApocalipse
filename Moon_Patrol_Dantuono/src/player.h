#pragma once
#include "timer.h"
#include "obstacle.h"
#include "shoot.h"

class Player {
private:
	float floorY;

	Vector2 velocity;
	float AlternVelocity;
	float gravity;
	Color color;
	bool jump;
	Rectangle colision;

	Shoot* shoot;

public:
	Player(
		float x, float y, 
		float velocityX, float velocityY, 
		float gravity, 
		float width, float height, 
		Color color);
	void DrawPlayer();
	void MovePlayer(Obstacle* flyObject);
	bool CheckColision(Obstacle* object);
	void RestartPlayer(Obstacle* object);
	float GetXVelocity();
	float GetX();
	float GetY();
};

static int jumpTimer = 0;

	

