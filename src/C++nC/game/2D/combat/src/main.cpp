#include "raylib.h"

int main(void)
{
    const int screenWidth = 1850;
    const int screenHeight = 1010;

    InitWindow(screenWidth, screenHeight, "Combat");
    SetTargetFPS(60);

    //NOTE: Main game loop
    while (!WindowShouldClose())
    {
        // TODO: Update your variables here

        //TODO: Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
