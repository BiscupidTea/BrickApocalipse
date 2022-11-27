#include "currentScreen.h"
#include "score.h"

void ScreenScene(bool& IsRunning, bool& multiplayer) {
	switch (gamescene)
	{
	case GameScene::Menu:
		SetExitKey(KEY_ESCAPE);
		MenuScene(multiplayer);
		break;
	case GameScene::GameLoop:
		SetExitKey(NULL);
		Gameplay(multiplayer);
		break;
	case GameScene::Rules:
		SetExitKey(NULL);
		DrawRules();
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
void MenuScene(bool& multiplayer) {
	BeginDrawing();
	DrawMenu();
	EndDrawing();
	CheckInputMenu(multiplayer);
}

void CreditsScene() {
	BeginDrawing();
	DrawCredits();
	EndDrawing();
}

void DrawMenu() {
	DrawBackgroundGame();
	DrawText("Moon Patrol Menu", GetScreenWidth() / 2 - (MeasureText("Moon Patrol Menu", 50)) / 2, GetScreenHeight() / 4 - 50, 50, WHITE);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2, GetScreenHeight() / 100 * 40, (MeasureText("Singleplayer", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2, GetScreenHeight() / 100 * 50, (MeasureText("Multiplayer", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Rules", 40)) / 2, GetScreenHeight() / 100 * 60, (MeasureText("Rules", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2, GetScreenHeight() / 100 * 70, (MeasureText("Credits", 40)), 60, GREEN);
	DrawRectangle(GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2, GetScreenHeight() / 100 * 80, (MeasureText("Exit", 40)), 60, GREEN);

	DrawText("Singleplayer", GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2, GetScreenHeight() / 100 * 40, 40, WHITE);
	DrawText("Multiplayer", GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2, GetScreenHeight() / 100 * 50, 40, WHITE);
	DrawText("Rules", GetScreenWidth() / 2 - (MeasureText("Rules", 40)) / 2, GetScreenHeight() / 100 * 60, 40, WHITE);
	DrawText("Credits", GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2, GetScreenHeight() / 100 * 70, 40, WHITE);
	DrawText("Exit", GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2, GetScreenHeight() / 100 * 80, 40, WHITE);

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

void CheckInputMenu(bool& multiplayer)
{
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Singleplayer", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 40), static_cast<float>((MeasureText("Singleplayer", 40))), 60 }))
		{
			gamescene = GameScene::GameLoop;
			multiplayer = false;
			RestartScore();
			RestartGameplay();
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Multiplayer", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 50), static_cast<float>((MeasureText("Multiplayer", 40))), 60 }))
		{
			gamescene = GameScene::GameLoop;
			multiplayer = true;
			RestartScore();
			RestartGameplay();
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Rules", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 60), static_cast<float>((MeasureText("Rules", 40))), 60 }))
		{
			gamescene = GameScene::Rules;
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Credits", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 70), static_cast<float>((MeasureText("Credits", 40))), 60 }))
		{
			gamescene = GameScene::Credits;
		}

		if (CheckCollisionPointRec(GetMousePosition(), Rectangle{
			static_cast<float>(GetScreenWidth() / 2 - (MeasureText("Exit", 40)) / 2),
			static_cast<float>(GetScreenHeight() / 100 * 80), static_cast<float>((MeasureText("Exit", 40))), 60 }))
		{
			gamescene = GameScene::Exit;
		}
	}
}

void DrawCredits() {
	DrawBackgroundGame();
	DrawRectangle(100, 100, 800, 600, BLACK);
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

void DrawRules()
{
	BeginDrawing();
	DrawBackgroundGame();
	DrawRectangle(100, 100, 800, 600, BLACK);
	DrawText("W A S D = Player 1 move                   F = shoot",
		GetScreenWidth() / 2 - (MeasureText("W A S D = Player 1 move                   F = shoot", 20) / 2),
		GetScreenHeight() / 2 -100 , 20, WHITE);

	DrawText("Key UP, Key DOWN, <- -> = Player 2 move        L = shoot",
		GetScreenWidth() / 2 - (MeasureText(" |, v, <- -> = Player 2 move        L = shoot", 20) / 2),
		GetScreenHeight() / 2 -50, 20, WHITE);

	DrawText("Todos los jugadores deben pasar el obstaculo para dar 1 punto",
		GetScreenWidth() / 2 - (MeasureText("Todos los jugadores deben pasar el obstaculo para dar 1 punto", 20) / 2),
		GetScreenHeight() / 2 , 20, WHITE);

	DrawText("Destruir 1 enemigo volador da 3 puntos",
		GetScreenWidth() / 2 - (MeasureText("Destruir 1 enemigo volador da 3 puntos", 20) / 2),
		GetScreenHeight() / 2 + 50, 20, WHITE);

	DrawText("(Espacio) para volver al Menu",
		GetScreenWidth() / 2 - (MeasureText("(Espacio) para volver al Menu", 20) / 2),
		GetScreenHeight() / 2 +100, 20, WHITE);

	if (IsKeyPressed(KEY_SPACE))
	{
		gamescene = GameScene::Menu;
	}
	VersionGame();
	EndDrawing();
}