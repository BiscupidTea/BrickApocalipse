#include "assets.h"

void LoadResources() {
	floor = LoadTexture("rsc/floorParallax.png");
	mountain = LoadTexture("rsc/mountainParallax.png");
	background = LoadTexture("rsc/backgroundParallax.png");

	floor.width = GetScreenWidth();
	floor.height = GetScreenWidth() / 8;
	mountain.width = GetScreenWidth();
	mountain.height = GetScreenHeight();
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
}

void UnloadResources() {
	UnloadTexture(floor);
	UnloadTexture(mountain);
	UnloadTexture(background);
}

void DrawBackgroundGame() {
	DrawBackgroundParallax();
	DrawMountainParallax();
	DrawFloorParallax();
	
}

void DrawFloorParallax() {
	scrollback -= 2.0f + (GetMovementPlayer() / 4);

	if (scrollback <= -floor.width * 2) scrollback = 0;
	DrawTextureEx(floor, { scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
	DrawTextureEx(floor, { floor.width * 2  + scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
}

void DrawMountainParallax() {
	scrollbackMountain -= 1.5f + (GetMovementPlayer() / 4);

	if (scrollbackMountain <= -mountain.width * 2) scrollbackMountain = 0;
	DrawTextureEx(mountain, { scrollbackMountain, static_cast<float>(200) }, 0, 2, WHITE);
	DrawTextureEx(mountain, { mountain.width * 2 + scrollbackMountain, static_cast<float>(200) }, 0, 2, WHITE);
	
}

void DrawBackgroundParallax() {
	scrollbackground -= 0.5f + (GetMovementPlayer() / 4);

	if (scrollbackground <= -background.width * 2) scrollbackground = 0;
	DrawTextureEx(background, { scrollbackground, static_cast<float>(0) }, 0, 2, WHITE);
	DrawTextureEx(background, { background.width * 2 + scrollbackground, static_cast<float>(0) }, 0, 2, WHITE);
}

