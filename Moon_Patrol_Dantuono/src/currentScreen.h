#pragma once
#include "raylib.h"

enum class GameScene {
	Menu,
	GameLoop,
	Credits,
	Exit,
};

static GameScene gamescene;

void ScreenScene(bool& IsRunning);
void GameplayScene();
void Gameplay();
void MenuScene();
void DrawMenu();
void CheckDefeat(bool isDefeat1);
void CheckDefeatM(bool isDefeat1, bool isDefeat2);
void CheckInputMenu();
void Draw();
void Update();
void RestartGameplay();
void VersionGame();
void CreditsScene();
void DrawCredits();