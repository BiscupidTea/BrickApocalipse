#include "score.h"

#include "raylib.h"

void DrawScore() {
	DrawText(TextFormat("%07i", score), GetScreenWidth() - MeasureText("0000000", 50) - 50, 0, 50, BLACK);
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