#pragma once
#include "raylib.h"

enum class GameScene {
	Menu,
	GameLoop,
	Credits,
	Exit,
};

static GameScene gamescene;

void ScreenScene(bool& IsRunning, bool& multiplayer);
void Gameplay(bool& multiplayer);
void MenuScene(bool& multiplayer);
void DrawMenu();
void CheckDefeat(bool isDefeat1);
void CheckDefeatM(bool isDefeat1, bool isDefeat2);
void CheckInputMenu(bool& multiplayer);
void Draw(bool& multiplayer);
void Update(bool& multiplayer);
void RestartGameplay();
void VersionGame();
void CreditsScene();
void DrawCredits();