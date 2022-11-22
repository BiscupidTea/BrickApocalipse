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

Player* player = new Player(10, static_cast<float>(screenHeight - 100), 300, 300, 350, 50, 50, RED);

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
    delete player;
    UnloadResources();
    CloseWindow();
}

void Draw() {
    player->DrawPlayer(); 
    object->DrawObstacle();
    flyObject->DrawObstacle();
}

void Update() {
    CheckDefeat(player->CheckColision(object));
    DrawBackgroundGame();
    player->MovePlayer(flyObject);
    object->MoveObstacle();
    object->RestartPosition();
    object->CheckJumpPlayer(object->GetX(), object->GetY());
    flyObject->MoveFlyObstacle();
    flyObject->RestartFlyPosition();
}

void VersionGame() {
    DrawText("Version: 0.4", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}

void DrawGameplay() {
    Update();
    Draw();
    DrawScore();
    VersionGame();
}

void RestartGameplay() {
    player->RestartPlayer(object);
}

float GetMovementPlayer() {
    return player->GetXVelocity();
}