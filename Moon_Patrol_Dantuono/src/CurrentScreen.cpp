#include "currentScreen.h"

void ScreenScene() {
	switch (gamescene)
	{
	case Menu:
		SetExitKey(KEY_ESCAPE);
		MenuScene();
		break;
	case Gameplay:
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
	DrawGameplay();
	if (IsKeyPressed(KEY_ESCAPE))
	{
		gamescene = GameScene::Menu;
	}
}

void DrawMenu() {
	DrawText("Moon Patrol Menu", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50, 50, WHITE);
	DrawText("(Espacio) para empezar", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 20, WHITE);
	DrawText("(Enter) para los creditos", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 + 50, 20, WHITE);
	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Gameplay;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		gamescene = GameScene::Credits;
	}
	RestartGameplay();
	VersionGame();
}

void CheckDefeat(bool isDefeat) {
	if (isDefeat)
	{
		gamescene = GameScene::Menu;
	}
}


void DrawCredits() {
	DrawText("Moon Patrol Credits", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 200, 50, WHITE);
	DrawText("Hecho por Manuel Dantuono", GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 - 50, 20, WHITE);
	DrawText("Creado con Raylib por Ray", GetScreenWidth() / 2 - 130, GetScreenHeight() / 2, 20, WHITE);
	DrawText("(Espacio) para volver al Menu", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 150, 20, WHITE);
	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Menu;
	}
	VersionGame();
}