#include "assets.h"

void LoadResources() {
	floor = LoadTexture("rsc/floorParallax.png");
	mountain = LoadTexture("rsc/mountainParallax.png");
	background = LoadTexture("rsc/backgroundParallax.png");

	floor.width = GetScreenWidth();
	floor.height = GetScreenWidth() / 16;
	mountain.width = GetScreenWidth() / 2;
	mountain.height = GetScreenHeight() / 2;
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
	scrollback -= GetMovementPlayer() * GetFrameTime();

	if (scrollback <= -floor.width * 2) scrollback = 0;
	DrawTextureEx(floor, { scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
	DrawTextureEx(floor, { floor.width * 2  + scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
}

void DrawMountainParallax() {
	scrollbackMountain -= GetMovementPlayer() / 4 * GetFrameTime();

	if (scrollbackMountain <= -mountain.width * 2) scrollbackMountain = 0;
	DrawTextureEx(mountain, { scrollbackMountain, 200 }, 0, 2, WHITE);
	DrawTextureEx(mountain, { mountain.width * 2 + scrollbackMountain, 200 }, 0, 2, WHITE);
	
}

void DrawBackgroundParallax() {
	scrollbackground -= GetMovementPlayer() / 2 * GetFrameTime();

	if (scrollbackground <= -background.width * 2) scrollbackground = 0;
	DrawTextureEx(background, { scrollbackground, 0 }, 0, 2, WHITE);
	DrawTextureEx(background, { background.width * 2 + scrollbackground, 0 }, 0, 2, WHITE);
}

