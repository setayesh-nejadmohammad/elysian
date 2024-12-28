#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "draw.h"
#include "info.h"
#include <string.h>

int Round = 0;


int main(void) {
    //*********************************************************************************************************
    //int n, m;
    printf("Enter the dimensions of the game:(it will be a n*m table)\n");
    printf("n = ");
    scanf("%d", &n); //get the table row num
    printf("m = ");
    scanf("%d", &m); //get the table column num

    //int map[17][17]={0};
    Map();
    generate_random();
    //*********************************************************************************************************
    InitWindow(0, 0, "main screen");

    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second

    Texture2D RoundGuide = LoadTexture("D:/git projects/elysian/pics/RoundGuide.png");

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);

        //DrawTexture(duck,100,100,WHITE);



        //ClearBackground(RAYWHITE);
        //draw table
        drawGrid();
        //DrawText("Elysian!", 850, 20, 80, DARKBLUE);

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            way(); // for Faz 4 we will add a MOUSE_BUTTON_RIGHT for second castle
            update();
            Round++;
        }

        //Draw the icons in the main window
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                if(map[i][j] == 'c'){
                    drawCastle1(i, j);
                }
                else if(map[i][j] == 'b'){
                    drawCastle2(i, j);
                }
                else if(map[i][j] == 'v'){
                    drawVillage(i, j);
                }
                else if(map[i][j] == 'x'){
                    drawBlock(i, j);
                }
                else if(map[i][j] == 'r'){
                    DrawRectangle(startX + i * cellSize, startY + j * cellSize, cellSize - 2, cellSize - 2, RED);
                }
                else{
                    Color level1 = (Color){0, 146, 115, 16};
                    Color level2 = (Color){0, 146, 115, 32};
                    Color level3 = (Color){0, 146, 115, 64};
                    Color level4 = (Color){0, 146, 115, 128};
                    Color level5 = (Color){0, 146, 115, 255};
                    if(map[i][j]== 1){
                        DrawRectangle(startX + i*cellSize, startY + j*cellSize, cellSize-2, cellSize-2, level1);
                    }
                    else if(map[i][j]== 2){
                        DrawRectangle(startX + i*cellSize, startY + j*cellSize, cellSize-2, cellSize-2, level2);
                    }
                    else if(map[i][j]== 3){
                        DrawRectangle(startX + i*cellSize, startY + j*cellSize, cellSize-2, cellSize-2, level3);
                    }
                    else if(map[i][j]== 4){
                        DrawRectangle(startX + i*cellSize, startY + j*cellSize, cellSize-2, cellSize-2, level4);
                    }
                    else if(map[i][j]== 5){
                        DrawRectangle(startX + i*cellSize, startY + j*cellSize, cellSize-2, cellSize-2, level5);
                    }
                }
            }
        }


        if(IsKeyPressed(KEY_ONE)){
            buyFood();
            update();
            Round++;
        }
        if(IsKeyPressed(KEY_TWO)){
            getWorker();
            update();
            Round++;
        }
        if(IsKeyPressed(KEY_THREE)){
            getSoldier();
            update();
            Round++;
        }
        if(IsKeyPressed(KEY_FOUR)){ //This Round will do NOTHING. :/
            update();
            Round++;
        }

        drawInformation(Round);  //define in draw.c


        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}