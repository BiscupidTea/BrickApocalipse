#include "assets.h"

void LoadResources() {
	floor1 = LoadTexture("rsc/floorParallax.png");
	mountain = LoadTexture("rsc/mountainParallax.png");
	background = LoadTexture("rsc/backgroundParallax.png");
	p1 = LoadTexture("rsc/player1.png");
	p2 = LoadTexture("rsc/player2.png");
	rock = LoadTexture("rsc/backgroundParallax.png");
	flyenemy = LoadTexture("rsc/backgroundParallax.png");

	floor1.width = GetScreenWidth();
	floor1.height = GetScreenWidth() / 16;
	mountain.width = GetScreenWidth() / 2;
	mountain.height = GetScreenHeight() / 2;
	background.width = GetScreenWidth();
	background.height = GetScreenHeight();
}

void UnloadResources() {
	UnloadTexture(floor1);
	UnloadTexture(mountain);
	UnloadTexture(background);
	UnloadTexture(p1);
	UnloadTexture(p2);
}

void DrawBackgroundGame() {
	DrawBackgroundParallax();
	DrawMountainParallax();
	DrawFloorParallax();
	
}

void DrawFloorParallax() {
	scrollback -= GetMovementPlayer() * GetFrameTime();

	if (scrollback <= -floor1.width * 2) scrollback = 0;
	DrawTextureEx(floor1, { scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
	DrawTextureEx(floor1, { floor1.width * 2  + scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
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

