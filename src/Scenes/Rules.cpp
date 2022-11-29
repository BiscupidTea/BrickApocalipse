#include "Rules.h"

void RulesScene()
{
	DrawRules();
}

void DrawRules()
{
	BeginDrawing();
	DrawBackgroundGame();
	DrawRectangle(100, 100, 800, 600, BLACK);
	DrawText("W A S D = Player 1 move                   F = shoot",
		GetScreenWidth() / 2 - (MeasureText("W A S D = Player 1 move                   F = shoot", 20) / 2),
		GetScreenHeight() / 2 - 100, 20, WHITE);

	DrawText("Key UP, Key DOWN, <- -> = Player 2 move        L = shoot",
		GetScreenWidth() / 2 - (MeasureText(" |, v, <- -> = Player 2 move        L = shoot", 20) / 2),
		GetScreenHeight() / 2 - 50, 20, WHITE);

	DrawText("Todos los jugadores deben pasar el obstaculo para dar 1 punto",
		GetScreenWidth() / 2 - (MeasureText("Todos los jugadores deben pasar el obstaculo para dar 1 punto", 20) / 2),
		GetScreenHeight() / 2, 20, WHITE);

	DrawText("Destruir 1 enemigo volador da 3 puntos",
		GetScreenWidth() / 2 - (MeasureText("Destruir 1 enemigo volador da 3 puntos", 20) / 2),
		GetScreenHeight() / 2 + 50, 20, WHITE);

	DrawText("(Espacio) para volver al Menu",
		GetScreenWidth() / 2 - (MeasureText("(Espacio) para volver al Menu", 20) / 2),
		GetScreenHeight() / 2 + 100, 20, WHITE);

	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Menu;
	}
	VersionGame();
	EndDrawing();
}