#pragma once
#include "raylib.h"

enum GameScene {
	Menu,
	GameLoop,
	Credits,
}static gamescene;

void ScreenScene();
void GameplayScene();
void Gameplay();
void MenuScene();
void DrawMenu();
void CheckDefeat(bool isDefeat1, bool isDefeat2);
void Draw();
void Update();
void RestartGameplay();
void VersionGame();
void CreditsScene();
void DrawCredits();