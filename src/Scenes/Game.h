#pragma once
#include "Objects/player.h"
#include "Objects/obstacle.h"
#include "currentScreen.h"
#include "tools/assets.h"
#include "Objects/score.h"

#include "raylib.h"

void RunGame();

void CheckDefeat(bool isDefeat1);
void CheckDefeatM(bool isDefeat1, bool isDefeat2);
void Gameplay(bool& multiplayer);
void Draw(bool& multiplayer);
void Update(bool& multiplayer);
void RestartGameplay();
void VersionGame();