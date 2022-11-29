#include "Menu.h"

void MenuScene(bool& multiplayer) {
	BeginDrawing();
	DrawMenu();
	EndDrawing();
	CheckInputMenu(multiplayer);
}

void DrawMenu() {
	DrawBackgroundGame();
	DrawText("BirckApocalipse", GetScreenWidth() / 2 - (MeasureText("BirckApocalipse", 50)) / 2, GetScreenHeight() / 4 - 50, 50, WHITE);
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