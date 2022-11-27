#include "obstacle.h"
#include "score.h"

Obstacle::Obstacle(float x, float y, float velocity, float width, float height) {
	this->colision.x = x;
	this->colision.y = y;
	this->velocity = velocity;
	this->colision.width = width;
	this->colision.height = height;
	this->passedPlayer = false;

	moveDown.lifeTime = 0;

	active = true;
	StartTimer(&moveUp, 0.4f);
}

void Obstacle::DrawObstacleFloor() {
	DrawRectangleRec(colision, WHITE);
	DrawTextureEx(rock, { colision.x, colision.y }, 0, 1, WHITE);
}

void Obstacle::DrawObstacleFly()
{
	DrawRectangleRec(colision, WHITE);
	DrawTextureEx(flyenemy, { colision.x, colision.y }, 0, 1, WHITE);
}

void Obstacle::MoveObstacle() {
	colision.x -= velocity * GetFrameTime();
}

void Obstacle::MoveFlyObstacle() {
	float timeUp = 2;
	float timeDown = 0.1f;
	float speedMovement = 2;

	UpdateTimer(&moveUp);
	UpdateTimer(&moveDown);
	if (active)
	{
		colision.x += velocity * GetFrameTime();

		if (!TimerDone(&moveUp))
		{
			colision.y -= (velocity / speedMovement) * GetFrameTime();
		}

		if (TimerDone(&moveUp))
		{
			StartTimer(&moveDown, timeDown);
		}

		if (!TimerDone(&moveDown))
		{
			colision.y += (velocity / speedMovement) * GetFrameTime();
		}

		if (colision.y > GetScreenHeight() / 2 - 120)
		{
			StartTimer(&moveUp, timeUp);
		}
	}
	else
	{
		colision.x = 0 - colision.width;
		colision.y = static_cast<float>(GetScreenHeight() / 4);
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
	
	Rectangle colisionObstacle = { colision.x, colision.y - 200, 10, 200 };
	Rectangle colisionPlayer = { X, Y, 2, colision.height  * 2 };

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
	return colision.x;
}

float Obstacle::GetY() {
	return colision.y;
}

float Obstacle::GetWidht() {
	return colision.width;
}

float Obstacle::GetHeight() {
	return colision.height;
}

void Obstacle::RestartPosition() {
	if (colision.x < 0 - colision.width)
	{
		colision.x = static_cast<float>(GetScreenWidth());
	}
}

void Obstacle::RestartFlyPosition() {
	if (colision.x > GetScreenWidth() + colision.width)
	{
		colision.x = 0 - colision.width;
	}
}

void Obstacle::RestartObstacle() {
	colision.x = static_cast<float>(GetScreenWidth());
	colision.y = static_cast<float>(GetScreenHeight() - 100);
}

void Obstacle::RestartFlyObstacle() {
	colision.x = static_cast<float>(GetScreenWidth());
}

bool Obstacle::GetPassedPlayer()
{
	return passedPlayer;
}

void Obstacle::SetPassedPlayer(bool is)
{
	passedPlayer = is;
}