#include <stdio.h>
#include "raylib.h"
#include "draw.h"

int main(void) {
    //*********************************************************************************************************
    int n, m;
    printf("Enter the dimensions of the game:(it will be a n*m table)\n");
    printf("n = ");
    scanf("%d", &n); //get the table row num
    printf("m = ");
    scanf("%d", &m); //get the table column num
    int map[17][17] = {0};
    Map(map, n, m);
    //*********************************************************************************************************
    InitWindow(0, 0, "main screen");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        //ClearBackground(GRAY);

        //DrawText("Elysian!", 850, 500, 80, BLACK);
        //DrawTexture(duck,100,100,WHITE);

        //ClearBackground(RAYWHITE);
        //Draw the icons in the main window
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'c') {
                    drawCastle(i, j, n, m);
                } else if (map[i][j] == 'v') {
                    drawVillage(i, j, n, m);
                } else if (map[i][j] == 'x') {
                    drawBlock(i, j, n, m);
                } else {
                    drawColor(i, j, n, m);
                }
            }
        }

        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}