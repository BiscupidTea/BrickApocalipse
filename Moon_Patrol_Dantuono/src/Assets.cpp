#include "assets.h"

void LoadResources() {
	floor = LoadTexture("rsc/floorParallax.png");

	floor.width = GetScreenWidth();
	floor.height = 40;
}

void UnloadResources() {
	UnloadTexture(floor);
}

void DrawFloorParallax() {
	scrollback -= 3.0f;

	if (scrollback <= -floor.width * 2) scrollback = 0;
	DrawTextureEx(floor, { scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
	DrawTextureEx(floor, { floor.width * 2  + scrollback, static_cast<float>(GetScreenHeight() - 50) }, 0, 2, WHITE);
}