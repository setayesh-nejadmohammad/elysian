#include <stdio.h>
#include "raylib.h"


const int maxRow = 17;
const int maxCol = 17;
const int cellSize = 50;
const int windowSize = 1050;
int startX = (windowSize - (maxCol*cellSize)) / 2 + 400;
int startY = (windowSize - (maxRow*cellSize)) / 2;

//draw a table.
void drawGrid(){
    for(int i=0;i<maxRow;i++){
        for(int j=0;j<maxCol;j++){
            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, LIGHTGRAY);
            DrawRectangleLines(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, DARKGRAY);
        }
    }
}

void DrawUser(int x, int y){    //x and y are chosen by user and this function will change the color of that position.
    DrawRectangle(startX + x*cellSize, startY + y*cellSize, cellSize, cellSize, RED);
}








int main(void) {
    InitWindow(0, 0, "main screen");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture2D duck= LoadTexture("D://FUM//projects//elysian//duck.png");
    Texture2D table1 = LoadTexture("D://FUM//projects//elysian//duck.png");
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);

        //DrawText("Elysian!", 850, 500, 80, BLACK);
        //DrawTexture(duck,100,100,WHITE);

        //ClearBackground(RAYWHITE);
        drawGrid();


        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
