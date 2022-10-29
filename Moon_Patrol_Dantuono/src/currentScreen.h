#pragma once
#include "raylib.h"

enum GameScene {
	Menu,
	Gameplay,
}static gamescene;

void ScreenScene();
void GameplayScene();
void MenuScene();
void DrawMenu();
void CheckDefeat(bool isDefeat);
void Draw();
void Update();
void RestartGameplay();
void VersionGame();




