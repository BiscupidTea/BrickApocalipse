#pragma once
#include "raylib.h"

#include "Menu.h"
#include "Game.h"
#include "Credits.h"
#include "Rules.h"
#include "tools/assets.h"
#include "Objects/score.h"

enum class GameScene {
	Menu,
	GameLoop,
	Rules,
	Credits,
	Exit,
};

static GameScene gamescene;

void ScreenScene(bool& IsRunning, bool& multiplayer);