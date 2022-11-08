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
}

void Obstacle::DrawObstacle() {
	this->colision = { x, y, width, height };
	DrawRectangleRec(colision, WHITE);
}

void Obstacle::MoveObstacle() {
	x -= velocity * GetFrameTime();
}

void Obstacle::MoveFlyObstacle() {
	int waveMovement = 40;
	int maxMovement = 80;

	if (active)
	{
		x += velocity * GetFrameTime();

		timer++;

		if (timer < waveMovement)
		{
			y -= (velocity / 2) * GetFrameTime();
		}
		else
		{
			y += (velocity / 2) * GetFrameTime();
			if (timer > maxMovement)
			{
				timer = 0;
			}
		}
	}
	else
	{
		x = 0 - width; 
		y = static_cast<float>(GetScreenHeight() / 4);
		if (GetRandomValue(1,100) == 50)
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