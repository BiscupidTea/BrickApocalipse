#include "score.h"

#include "raylib.h"

void DrawScore() {
	DrawText(TextFormat("Puntuacion: %02i", score), 10, 10, 40, BLUE);
}

void DrawMaxScore() {
	if (score > maxScore)
	{
		maxScore = score;
	}

	if (maxScore > 0)
	{
		DrawText(TextFormat("Maxima Puntuacion: %02i", maxScore), GetScreenWidth() / 2 - 300, 10, 60, RED);
	}
}

void RestartScore() {
	score = 0;
}

void AddScore(int Score) {
	score += Score;
}