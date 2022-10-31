#pragma once
#include "raylib.h"

static Texture2D floor;
static Texture2D mountain;
static Texture2D background;

static float scrollback = 0;
static float scrollbackMountain = 0;
static float scrollbackground = 0;

void LoadResources();
void UnloadResources();
void DrawBackgroundGame();
void DrawFloorParallax();
void DrawMountainParallax();
void DrawBackgroundParallax();
float GetMovementPlayer();