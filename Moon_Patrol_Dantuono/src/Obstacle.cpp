#include "obstacle.h"
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
	}
	
}

bool Obstacle::CheckColisionShoot(Vector2 center, float radius) {
	if (CheckCollisionCircleRec(center, radius, colision))
	{
		active = false;
		return true;
	}
	return false;
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