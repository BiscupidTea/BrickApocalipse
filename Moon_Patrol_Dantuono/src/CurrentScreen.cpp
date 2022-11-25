#include "currentScreen.h"
#include "score.h"

void ScreenScene(bool& IsRunning) {
	switch (gamescene)
	{
	case GameScene::Menu:
		SetExitKey(KEY_ESCAPE);
		MenuScene();
		break;
	case GameScene::GameLoop:
		SetExitKey(NULL);
		GameplayScene();
		break;
	case GameScene::Credits:
		SetExitKey(NULL);
		CreditsScene();
		break;
	case GameScene::Exit:
		IsRunning = false;
		break;
	default:
		break;
	}
}
void MenuScene() {
	BeginDrawing();
	DrawMenu();
	EndDrawing();
	CheckInputMenu();
}

void CreditsScene() {
	BeginDrawing();
	DrawCredits();
	EndDrawing();
}

void GameplayScene() {
	Gameplay();
}

void DrawMenu() {
	DrawText("Moon Patrol Menu", GetScreenWidth() / 2 - (MeasureText("Moon Patrol Menu", 50)) / 2, GetScreenHeight() / 4 - 50, 50, WHITE);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2, GetScreenHeight() / 100 * 40, (MeasureText("Singleplayer", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2, GetScreenHeight() / 100 * 50, (MeasureText("Multiplayer", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2, GetScreenHeight() / 100 * 60, (MeasureText("Credits", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2, GetScreenHeight() / 100 * 70, (MeasureText("Exit", 40)), 60, GREEN);

	DrawText("Singleplayer", GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2, GetScreenHeight() / 100 * 40, 40, WHITE);
	DrawText("Multiplayer", GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2, GetScreenHeight() / 100 * 50, 40, WHITE);
	DrawText("Credits", GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2, GetScreenHeight() / 100 * 60, 40, WHITE);
	DrawText("Exit", GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2, GetScreenHeight() / 100 * 70, 40, WHITE);

	VersionGame();
}

void CheckDefeat(bool isDefeat1) {
	if (!isDefeat1)
	{
		gamescene = GameScene::Menu;
	}
}

void CheckDefeatM(bool isDefeat1, bool isDefeat2) {
	if (!isDefeat1 || !isDefeat2)
	{
		gamescene = GameScene::Menu;
	}
}

void CheckInputMenu()
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 40), static_cast<float>((MeasureText("Singleplayer", 40))), 60 }))
		{
			gamescene = GameScene::GameLoop;
			RestartScore();
			RestartGameplay();
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 50), static_cast<float>((MeasureText("Multiplayer", 40))), 60 }))
		{
			gamescene = GameScene::GameLoop;
			
			RestartScore();
			RestartGameplay();
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 60), static_cast<float>((MeasureText("Credits", 40))), 60 }))
		{
			gamescene = GameScene::Credits;
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 70), static_cast<float>((MeasureText("Exit", 40))), 60 }))
		{
			gamescene = GameScene::Exit;
		}
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