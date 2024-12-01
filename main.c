#include <stdio.h>
#include "raylib.h"

int main(void) {
    InitWindow(0, 0, "main screen");
    //InitWindow(400, 400, "not main screen");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture2D duck= LoadTexture("D://FUM//projects//elysian//duck.png");
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);

        DrawText("Elysian!", 850, 500, 80, BLACK);
        //DrawTexture(duck,100,100,WHITE);

        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
