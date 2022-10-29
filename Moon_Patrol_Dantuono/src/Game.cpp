#include "game.h"
#include "player.h"
#include "obstacle.h"

#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

Player* player = new Player(10, screenHeight - 100, 300, 50, 50);

void Draw();
void Update();
void VersionGame();


void RunGame() {
    InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);   
        Draw();      
        Update();

        VersionGame();
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
    player->CheckColision();
}

void VersionGame() {
    DrawText("Version: 0.1", GetScreenWidth() - 150, GetScreenHeight() - 25, 25, WHITE);
}