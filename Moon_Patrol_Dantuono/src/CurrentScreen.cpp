#include "currentScreen.h"

void ScreenScene() {
	switch (gamescene)
	{
	case Menu:
		MenuScene();
		break;
	case Gameplay:
		GameplayScene();
		break;
	default:
		break;
	}
}
void MenuScene() {
	DrawMenu();
}

void DrawMenu() {
	DrawText("Moon Patrol Menu", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 50, 50, WHITE);
	DrawText("(Espacio) para empezar", GetScreenWidth() / 2 - 100, GetScreenHeight() / 2, 20, WHITE);
	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Gameplay;
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
