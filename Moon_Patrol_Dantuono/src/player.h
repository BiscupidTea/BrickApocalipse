#pragma once
#include "timer.h"
#include "obstacle.h"
#include "shoot.h"

class Player {
private:
	float floorY;

	bool isAlive;
	Vector2 velocity;
	float AlternVelocity;
	float gravity;
	Color color;
	bool jump;
	Rectangle colision;

public:
	Player(
		float x, float y, 
		float velocityX, float velocityY, 
		float gravity, 
		float width, float height, 
		Color color);
	void DrawPlayer();
	void MovePlayer1(Obstacle* flyObject, Shoot* shoot1);
	void MovePlayer2(Obstacle* flyObject, Shoot* shoot2);
	void CheckColision(Obstacle* object);
	void RestartPlayer();
	float GetXVelocity();
	float GetX();
	float GetY();
	bool IsAlive();
};

static int jumpTimer = 0;

	

