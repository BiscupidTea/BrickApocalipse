#include "game.h"
#include "player.h"
#include "obstacle.h"
#include "currentScreen.h"
#include "assets.h"

#include "raylib.h"

int screenWidth = 1024;
int screenHeight = 768;


Player* player = new Player(10, static_cast<float>(screenHeight - 100), 300, 50, 50);


void RunGame() {
    InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
    LoadResources();
    SetTargetFPS(60);
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
}

void Update() {   
    CheckDefeat(player->CheckColision());
    DrawBackgroundGame();
    player->MovePlayer();
}

void VersionGame() {
    DrawText("Version: 0.2", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}

void DrawGameplay() {
    Update();
    Draw();
    VersionGame();
}

void RestartGameplay() {
    player->RestartPlayer();
}

float GetMovementPlayer() {
    return player->GetX() * GetFrameTime();
}