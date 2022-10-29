#include "player.h"

#include "raylib.h"

Player::Player(float x, float y, float velocity, float width, float height){
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->width = width;
	this->height = height;

	object = new Obstacle(800, 450 - 100, 200, 50, 50);
}

void Player::DrawPlayer() {
	colision = { x, y, width, height };
	DrawRectangleRec(colision, RED);
	object->DrawObstacle();
}

void Player::MovePlayer() {
	if (IsKeyDown(KEY_A))
	{
		x -= velocity * GetFrameTime();
	}

	if (IsKeyDown(KEY_D))
	{
		x += velocity * GetFrameTime();
	}
	object->MoveObstacle();
	object->RestartPosition();
}

void Player::CheckColision() {
	if (CheckCollisionRecs(colision, Rectangle{ object->GetX(), object->GetY(), object->GetWidht(), object->GetHeight() }))
	{
		DrawText("Colision Detectada!", 10, 10, 30, RED);
	}
	else
	{
		DrawText("Colision NO Detectada!", 10, 10, 30, BLUE);
	}
}
