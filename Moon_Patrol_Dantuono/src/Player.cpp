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
	isAlive = true;

	jump = false;
}

void Player::DrawPlayer() {
	DrawRectangleRec(colision, color);
}

void Player::MovePlayer1(Obstacle* flyObject, Shoot* shoot1) {

	shoot1->LogicShoot1();
	if (!shoot1->IsActive())
	{
		shoot1->GetPosition(GetX() + colision.width / 2, GetY());
	}

	if (IsKeyDown(KEY_A))
	{
		colision.x -= velocity.x * GetFrameTime();
	}

	if (IsKeyDown(KEY_D))
	{
		colision.x += velocity.x * GetFrameTime();
	}

	if (IsKeyPressed(KEY_W) && !jump)
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

	if (flyObject->CheckColisionShoot({ shoot1->GetX(), shoot1->GetY() }, shoot1->GetRadius()))
	{
		shoot1->ActiveFalse();
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

void Player::MovePlayer2(Obstacle* flyObject, Shoot* shoot2) {

	shoot2->LogicShoot2();
	if (!shoot2->IsActive())
	{
		shoot2->GetPosition(GetX() + colision.width / 2, GetY());
	}

	if (IsKeyDown(KEY_LEFT))
	{
		colision.x -= velocity.x * GetFrameTime();
	}

	if (IsKeyDown(KEY_RIGHT))
	{
		colision.x += velocity.x * GetFrameTime();
	}

	if (IsKeyPressed(KEY_UP) && !jump)
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

	if (flyObject->CheckColisionShoot({ shoot2->GetX(), shoot2->GetY() }, shoot2->GetRadius()))
	{
		shoot2->ActiveFalse();
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

void Player::CheckColision(Obstacle* object) {
	if (CheckCollisionRecs(colision, Rectangle{ object->GetX(), object->GetY(), object->GetWidht(), object->GetHeight() }))
	{
		isAlive = false;
	}
	else
	{
		isAlive = true;
	}
}

void Player::RestartPlayer() {
	colision.x = 10;
	colision.y = static_cast<float>(GetScreenHeight() - 100);
	isAlive = true;
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

bool Player::IsAlive()
{
	return isAlive;
}