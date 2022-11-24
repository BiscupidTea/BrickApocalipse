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
	LoadResources();
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		ScreenScene();
		EndDrawing();

	}
	delete player1;
	delete player2;
	UnloadResources();
	CloseWindow();
}

void Draw() {

	player1->DrawPlayer();
	player2->DrawPlayer();

	object->DrawObstacle();
	flyObject->DrawObstacle();
}

void Update() {
	player1->CheckColision(object);
	player1->MovePlayer1(flyObject, shoot1);
	
	player2->CheckColision(object);
	player2->MovePlayer2(flyObject, shoot2);
	
	CheckDefeat(player1->IsAlive(), player2->IsAlive());
	DrawBackgroundGame();

	object->MoveObstacle();
	object->RestartPosition();
	object->CheckJumpPlayer(object->GetX(), object->GetY());

	flyObject->MoveFlyObstacle();
	flyObject->RestartFlyPosition();
}

void VersionGame() {
	DrawText("Version: 0.4", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}

void Gameplay() {
	Update();
	Draw();
	DrawScore();
	VersionGame();
}

void RestartGameplay() {
	player1->RestartPlayer(object);
	player2->RestartPlayer(object);
}

float GetMovementPlayer() {
	return player1->GetXVelocity();
}