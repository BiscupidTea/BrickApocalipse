#include "shoot.h"

Shoot::Shoot(Vector2 position, float speed, float radius) {
	this->position = position;
	this->speed = speed;
	this->radius = radius;

	active = false;

}


void Shoot::LogicShoot1() {
	if (IsKeyPressed(KEY_F))
	{
		active = true;
	}

	if (active)
	{
		DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, RED);
		position.y -= speed * GetFrameTime();

		if (position.y + radius < 0)
		{
			active = false;
		}
	}
}

void Shoot::LogicShoot2() {
	if (IsKeyPressed(KEY_L))
	{
		active = true;
	}

	if (active)
	{
		DrawCircle(static_cast<int>(position.x), static_cast<int>(position.y), radius, RED);
		position.y -= speed * GetFrameTime();

		if (position.y + radius < 0)
		{
			active = false;
		}
	}
}

void Shoot::GetPosition(float x, float y) {
	position.x = x;
	position.y = y;
}

bool Shoot::IsActive() {
	if (active)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Shoot::GetX() {
	return position.x;
}

float Shoot::GetY() {
	return position.y;
}

float Shoot::GetRadius() {
	return radius;
}

void Shoot::ActiveFalse() {
	active = false;
}