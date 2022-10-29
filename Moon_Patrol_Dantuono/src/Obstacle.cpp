#include "obstacle.h"

Obstacle::Obstacle(float x, float y, float velocity, float width, float height) {
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->width = width;
	this->height = height;
}

void Obstacle::DrawObstacle() {
	this->colision = { x, y, width, height };
	DrawRectangleRec(colision, WHITE);
}

void Obstacle::MoveObstacle() {
	x -= velocity * GetFrameTime();
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

void Obstacle::RestartObstacle() {
	x = static_cast<float>(GetScreenWidth());
	y = static_cast<float>(GetScreenHeight() - 100);
}