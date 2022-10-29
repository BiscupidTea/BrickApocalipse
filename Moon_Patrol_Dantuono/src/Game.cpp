#include "game.h"
#include "player.h"
#include "obstacle.h"
#include "currentScreen.h"

#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;


Player* player = new Player(10, screenHeight - 100, 300, 50, 50);


void RunGame() {
    InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);   
        ScreenScene();
        EndDrawing();
    }
    delete player;

    CloseWindow();
}

void Draw() {
    player->DrawPlayer();
}

void Update() {
    player->MovePlayer();  
    CheckDefeat(player->CheckColision());
}

void VersionGame() {
    DrawText("Version: 0.1", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}

void GameplayScene() {
    Draw();
    Update();
    VersionGame();
}

void RestartGameplay() {
    player->RestartPlayer();
}