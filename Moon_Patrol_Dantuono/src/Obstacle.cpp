#include "obstacle.h"
#include "score.h"

#include "raymath.h"

Obstacle::Obstacle(float x, float y, float velocity, float width, float height) {
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->width = width;
	this->height = height;

	active = true;
	StartTimer(&moveUp, 0.4f);
}

void Obstacle::DrawObstacle() {
	this->colision = { x, y, width, height };
	DrawRectangleRec(colision, WHITE);
}

void Obstacle::MoveObstacle() {
	x -= velocity * GetFrameTime();
}

void Obstacle::MoveFlyObstacle() {
	float timeUp = 2;
	float timeDown = 0.1f;
	float speedMovement = 2;

	UpdateTimer(&moveUp);
	UpdateTimer(&moveDown);
	if (active)
	{
		x += velocity * GetFrameTime();

		if (!TimerDone(&moveUp))
		{
			y -= (velocity / speedMovement) * GetFrameTime();
		}

		if (TimerDone(&moveUp))
		{
			StartTimer(&moveDown, timeDown);
		}

		if (!TimerDone(&moveDown))
		{
			y += (velocity / speedMovement) * GetFrameTime();
		}

		if (y > GetScreenHeight() / 2 - 120)
		{
			StartTimer(&moveUp, timeUp);
		}
	}
	else
	{
		x = 0 - width; 
		y = static_cast<float>(GetScreenHeight() / 4);
		if (GetRandomValue(1,300) == 50)
		{
			active = true;
		}
	}
	
}

bool Obstacle::CheckColisionShoot(Vector2 center, float radius) {
	if (CheckCollisionCircleRec(center, radius, colision))
	{
		active = false;
		AddScore(3);
		return true;
		
	}
	return false;
}

void Obstacle::CheckJumpPlayer(float X, float Y) {
	
	Rectangle colisionObstacle = { x, y - 200, 10, 200 };
	Rectangle colisionPlayer = { X, Y, 2, height  * 2 };

	if (CheckCollisionRecs(colisionPlayer, colisionObstacle))
	{
		checkcolision++;
		if (checkcolision == 1)
		{
			AddScore(1);
		}
		
	}
	else
	{
		checkcolision = 0;
	}
}

float Obstacle::GetX() {
	return x;
}

float Obstacle::GetY() {
	return y;
}

float Obstacle::GetWidht() {
	return width;
}

float Obstacle::GetHeight() {
	return height;
}

void Obstacle::RestartPosition() {
	if (x < 0 - width)
	{
		x = static_cast<float>(GetScreenWidth());
	}
}

void Obstacle::RestartFlyPosition() {
	if (x > GetScreenWidth() + width)
	{
		x = 0 - width;
	}
}

void Obstacle::RestartObstacle() {
	x = static_cast<float>(GetScreenWidth());
	y = static_cast<float>(GetScreenHeight() - 100);
}