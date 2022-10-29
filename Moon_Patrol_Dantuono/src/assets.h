#pragma once
#include "raylib.h"

static Texture2D floor;

static float scrollback = 0;

void LoadResources();
void UnloadResources();
void DrawFloorParallax();