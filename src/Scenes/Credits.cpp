#include "Credits.h"

void CreditsScene() {
	BeginDrawing();
	DrawCredits();
	EndDrawing();
}

void DrawCredits() {
	DrawBackgroundGame();
	DrawRectangle(100, 100, 800, 600, BLACK);
	DrawText("Credits",
		GetScreenWidth() / 2 - (MeasureText("Moon Patrol Credits", 50) / 2),
		GetScreenHeight() / 2 - 200, 50, WHITE);

	DrawText("Hecho por Manuel Dantuono y Enzo Coletta",
		GetScreenWidth() / 2 - (MeasureText("Hecho por Manuel Dantuono y Enzo Coletta", 20) / 2),
		GetScreenHeight() / 2 - 50, 20, WHITE);

	DrawText("Creado con Raylib por Ray",
		GetScreenWidth() / 2 - (MeasureText("Creado con Raylib por Ray", 20) / 2),
		GetScreenHeight() / 2, 20, WHITE);

	DrawText("(Espacio) para volver al Menu",
		GetScreenWidth() / 2 - (MeasureText("(Espacio) para volver al Menu", 20) / 2),
		GetScreenHeight() / 2 + 150, 20, WHITE);

	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Menu;
	}
	VersionGame();
}