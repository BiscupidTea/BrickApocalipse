#include "player.h"

#include "raylib.h"
#include "raymath.h"

#include <iostream>
using namespace std;

Player::Player(float x, float y, float velocityX, float velocityY, float gravity, float width, float height) {
	this->x = x;
	this->y = y;
	this->velocity.x = velocityX;
	this->floorY = y;
	this->velocity.y = velocityY;
	this->AlternVelocity = velocityY;
	this->gravity = gravity;
	this->width = width;
	this->height = height;

	jump = false;

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
	cout << AlternVelocity << endl;
	shoot->LogicShoot();
	if (!shoot->IsActive())
	{
		shoot->GetPosition(GetX() + width / 2, GetY());
	}


	if (IsKeyDown(KEY_A))
	{
		x -= velocity.x * GetFrameTime();
	}

	if (IsKeyDown(KEY_D))
	{
		x += velocity.x * GetFrameTime();
	}

	if (IsKeyPressed(KEY_SPACE) && !jump)
	{
		jump = true;
		AlternVelocity = velocity.y;
	}

	if (jump)
	{
		y -= AlternVelocity * GetFrameTime();
		AlternVelocity -= gravity * GetFrameTime();
	}

	if (y > floorY)
	{
		y = floorY;
		jump = false;
	}

	if (flyObject->CheckColisionShoot({ shoot->GetX(), shoot->GetY() }, shoot->GetRadius()))
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
	return x / velocity.x * 2;
}

float Player::GetX() {
	return x;
}

float Player::GetY() {
	return y;
}
