#pragma once

class Player {
private:
	float x;
	float y;

	float velocity;
	float width;
	float height;

public:
	Player(float x, float y, float velocity, float width, float height);
	void DrawPlayer();
	void MovePlayer();
};


	

