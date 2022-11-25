#include "game.h"
#include "player.h"
#include "obstacle.h"
#include "currentScreen.h"
#include "assets.h"
#include "score.h"

#include "raylib.h"

int screenWidth = 1024;
int screenHeight = 768;

Obstacle* object = new Obstacle(static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight() - 100), 200, 50, 50);
Obstacle* flyObject = new Obstacle(100, static_cast<float>(GetScreenHeight() + 200), 200, 50, 50);

Player* player1 = new Player(10, static_cast<float>(screenHeight - 100), 300, 300, 350, 50, 50, RED);
Shoot* shoot1 = new Shoot({ 0,0 }, 400, 10);

Player* player2 = new Player(10, static_cast<float>(screenHeight - 100), 300, 300, 350, 50, 50, BLUE);
Shoot* shoot2 = new Shoot({ 0,0 }, 400, 10);

void RunGame() {
	InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
	SetExitKey(KEY_NULL);
	LoadResources();
	bool IsRunning = true;
	bool multiplayer = false;

	while (!WindowShouldClose() && IsRunning)
	{
		ClearBackground(BLACK);
		ScreenScene(IsRunning, multiplayer);
	}

	delete player1;
	delete player2;
	UnloadResources();
	CloseWindow();
}

void Draw(bool& multiplayer) {

	BeginDrawing();
	DrawBackgroundGame();

	if (shoot1->IsActive())
	{
		shoot1->DrawBullet();
	}

	if (multiplayer)
	{
		if (shoot2->IsActive())
		{
			shoot2->DrawBullet();
		}
	}

	player1->DrawPlayer();
	if (multiplayer)
	{
		player2->DrawPlayer();
	}

	object->DrawObstacle();
	flyObject->DrawObstacle();
	EndDrawing();
}

void Update(bool& multiplayer) {
	player1->MovePlayer1(flyObject, shoot1);
	player1->CheckColision(object);

	if (multiplayer)
	{
		player2->MovePlayer2(flyObject, shoot2);
		player2->CheckColision(object);
	}

	if (multiplayer)
	{
		CheckDefeatM(player1->IsAlive(), player2->IsAlive());
	}
	else
	{
		CheckDefeat(player1->IsAlive());
	}

	object->MoveObstacle();
	object->RestartPosition();
	object->CheckJumpPlayer(object->GetX(), object->GetY());

	flyObject->MoveFlyObstacle();
	flyObject->RestartFlyPosition();
}

void VersionGame() {
	DrawText("Version: 0.4", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}

void Gameplay(bool& multiplayer) {
	Update(multiplayer);
	Draw(multiplayer);
	DrawScore();
	VersionGame();
}

void RestartGameplay() {
	player1->RestartPlayer();
	player2->RestartPlayer();
	object->RestartObstacle();
	flyObject->RestartFlyObstacle();
}

float GetMovementPlayer() {
	return player1->GetXVelocity();
}