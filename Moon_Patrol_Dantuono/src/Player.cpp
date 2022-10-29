#include "player.h"

#include "raylib.h"

Player::Player(float x, float y, float velocity, float width, float height) {
	this->x = x;
	this->y = y;
	this->velocity = velocity;
	this->width = width;
	this->height = height;
}

void Player::DrawPlayer() {
	DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), RED);
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
}
