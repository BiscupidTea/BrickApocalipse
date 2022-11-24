#include "currentScreen.h"
#include "score.h"

void ScreenScene() {
	switch (gamescene)
	{
	case Menu:
		SetExitKey(KEY_ESCAPE);
		MenuScene();
		break;
	case GameLoop:
		SetExitKey(NULL);
		GameplayScene();		
		break;
	case Credits:
		SetExitKey(NULL);
		CreditsScene();
		break;
	default:
		break;
	}
}
void MenuScene() {
	DrawMenu();
}

void CreditsScene() {
	DrawCredits();
}

void GameplayScene() {
	Gameplay();
	if (IsKeyPressed(KEY_ESCAPE))
	{
		gamescene = GameScene::Menu;
	}
}

void DrawMenu() {
	DrawText("Moon Patrol Menu", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50, 50, WHITE);
	DrawText("(Espacio) para empezar", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 20, WHITE);
	DrawText("(Enter) para los creditos", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 50, 20, WHITE);
	DrawMaxScore();
	RestartScore();
	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::GameLoop;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		gamescene = GameScene::Credits;
	}
	RestartGameplay();
	VersionGame();
}

void CheckDefeat(bool isDefeat1, bool isDefeat2) {
	if (!isDefeat1 || !isDefeat2)
	{
		gamescene = GameScene::Menu;
	}
}


void DrawCredits() {
	DrawText("Moon Patrol Credits", 
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