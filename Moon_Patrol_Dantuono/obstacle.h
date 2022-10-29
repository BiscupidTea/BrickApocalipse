#pragma once

class Obstacle {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;

public:
	Obstacle(float x, float y, float velocity, float width, float height);
	void DrawObstacle();
	void MoveObstacle();
	void RestartPosition();
};
