#pragma once
#include "raylib.h"

static Texture2D floor1;
static Texture2D mountain;
static Texture2D background;
static Texture2D p1;
static Texture2D p2;
static Texture2D rock;
static Texture2D flyenemy;

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