#include "game.h"
#include "player.h"

#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;
Player* player = new Player(10, screenHeight - 100, 300, 50, 50);

void Draw();
void Update();


void RunGame() {
    InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);   
        Draw();      
        Update();

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
    
}