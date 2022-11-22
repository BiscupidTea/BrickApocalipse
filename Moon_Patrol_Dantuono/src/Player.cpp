#include "player.h"

#include "raylib.h"
#include "raymath.h"

#include <iostream>
using namespace std;

Player::Player(float x, float y, float velocityX, float velocityY, float gravity, float width, float height, Color color) {
	this->colision.x = x;
	this->colision.y = y;
	this->velocity.x = velocityX;
	this->floorY = y;
	this->velocity.y = velocityY;
	this->AlternVelocity = velocityY;
	this->gravity = gravity;
	this->colision.width = width;
	this->colision.height = height;
	this->color = color;

	jump = false;

	shoot = new Shoot({ 0,0 }, 400, 10);

}

void Player::DrawPlayer() {
	DrawRectangleRec(colision, color);
}

void Player::MovePlayer(Obstacle* flyObject) {
	cout << colision.x << endl;
	shoot->LogicShoot();
	if (!shoot->IsActive())
	{
		shoot->GetPosition(GetX() + colision.width / 2, GetY());
	}


	if (IsKeyDown(KEY_A))
	{
		colision.x -= velocity.x * GetFrameTime();
	}

	if (IsKeyDown(KEY_D))
	{
		colision.x += velocity.x * GetFrameTime();
	}

	if (IsKeyPressed(KEY_SPACE) && !jump)
	{
		jump = true;
		AlternVelocity = velocity.y;
	}

	if (jump)
	{
		colision.y -= AlternVelocity * GetFrameTime();
		AlternVelocity -= gravity * GetFrameTime();
	}

	if (colision.y > floorY)
	{
		colision.y = floorY;
		jump = false;
	}

	if (flyObject->CheckColisionShoot({ shoot->GetX(), shoot->GetY() }, shoot->GetRadius()))
	{
		shoot->ActiveFalse();
	}

	if (colision.x + colision.width > GetScreenWidth())
	{
		colision.x = GetScreenWidth() - colision.width;
	}
	
	if (colision.x < 0)
	{
		colision.x = 0;
	}

}

bool Player::CheckColision(Obstacle* object) {
	if (CheckCollisionRecs(colision, Rectangle{ object->GetX(), object->GetY(), object->GetWidht(), object->GetHeight() }))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::RestartPlayer(Obstacle* object) {
	colision.x = 10;
	colision.y = static_cast<float>(GetScreenHeight() - 100);

	object->RestartObstacle();
}

float Player::GetXVelocity() {
	return velocity.x;
}

float Player::GetX() {
	return colision.x;
}

float Player::GetY() {
	return colision.y;
}
