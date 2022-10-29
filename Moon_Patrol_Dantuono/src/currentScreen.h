#pragma once
#include "raylib.h"

enum GameScene {
	Menu,
	Gameplay,
	Credits,
}static gamescene;

void ScreenScene();
void GameplayScene();
void DrawGameplay();
void MenuScene();
void DrawMenu();
void CheckDefeat(bool isDefeat);
void Draw();
void Update();
void RestartGameplay();
void VersionGame();
void CreditsScene();
void DrawCredits();




