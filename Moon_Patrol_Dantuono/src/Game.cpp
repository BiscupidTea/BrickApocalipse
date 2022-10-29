#include "game.h"
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 450;

void RunGame() {
    InitWindow(screenWidth, screenHeight, "Moon Patrol By Manuel Dantuono");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);     

        EndDrawing();
    }
    CloseWindow();
}