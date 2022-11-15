#include "player.h"

#include "raylib.h"
#include "raymath.h"

Player::Player(float x, float y, float velocity, float width, float height){
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->width = width;
	this->height = height;

	object = new Obstacle(static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight() - 100), 200, 50, 50);
	flyObject = new Obstacle(100, static_cast<float>(GetScreenHeight() + 200), 200, 50, 50);
	shoot = new Shoot({ 0,0 }, 400, 10);
	
}

void Player::DrawPlayer() {
	colision = { x, y, width, height };	
	DrawRectangleRec(colision, RED);
	object->DrawObstacle();
	flyObject->DrawObstacle();
	
}

void Player::MovePlayer() {
	float timeJump = 0.5f;
	float timeDown = 0.6f;
	float speedJump = 1.5f;

	shoot->LogicShoot();
	if (!shoot->IsActive())
	{
		shoot->GetPosition(GetX() + width / 2, GetY());
	}

	if (IsKeyDown(KEY_A))
	{
		x -= velocity * GetFrameTime();
	}

	if (IsKeyDown(KEY_D))
	{
		x += velocity * GetFrameTime();
	}

	if (IsKeyPressed(KEY_SPACE))
	{			
		if (!jump)
		{
			StartTimer(&jumpTime, timeJump);
		}
		jump = true;
		
	}
	UpdateTimer(&jumpTime);
	UpdateTimer(&jumpDown);

	if (jump)
	{
		if (!TimerDone(&jumpTime))
		{
			y -= (velocity * speedJump) * GetFrameTime();
		}

		if (TimerDone(&jumpTime))
		{
			StartTimer(&jumpDown, timeDown);
		}
		
		if (!TimerDone(&jumpDown))
		{
			jump = false;
		}
	}
	if (!TimerDone(&jumpDown))
	{
		y += (velocity * speedJump) * GetFrameTime();
	}
	
	if (y > static_cast<float>(GetScreenHeight() - 100))
	{
		y = static_cast<float>(GetScreenHeight() - 100);
	}
	
	if (flyObject->CheckColisionShoot({shoot->GetX(), shoot->GetY()}, shoot->GetRadius()))
	{
		shoot->ActiveFalse();
	}

	object->MoveObstacle();
	object->RestartPosition();
	object->CheckJumpPlayer(GetX(), GetY());
	flyObject->MoveFlyObstacle();
	flyObject->RestartFlyPosition();
	
}

bool Player::CheckColision() {
	if (CheckCollisionRecs(colision, Rectangle{ object->GetX(), object->GetY(), object->GetWidht(), object->GetHeight() }))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::RestartPlayer() {
	x = 10;
	y = static_cast<float>(GetScreenHeight() - 100);

	object->RestartObstacle();
}

float Player::GetXVelocity() {
	return x / velocity * 2;
}

float Player::GetX() {
	return x;
}

float Player::GetY() {
	return y;
}
