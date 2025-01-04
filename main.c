#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "draw.h"
#include "info.h"
#include <string.h>




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
    for(int i = 0; i < n; i++){      // Fill map1 and map2 with map
        for(int j = 0; j < m; j++){
            map1[i][j] = map[i][j];
            map2[i][j] = map[i][j];
        }
    }
    //*********************************************************************************************************
    InitWindow(0, 0, "main screen");

    SetTargetFPS(120);               // Set our game to run at 60 frames-per-second

    //Texture2D RoundGuide = LoadTexture("D:/git projects/elysian/pics/RoundGuide.png");

    //--------------------------------------------------------------------------------------

    bool endGame = true;
    // Main game loop
    while (!WindowShouldClose() && endGame)    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);

        Texture2D background = LoadTexture("D://git projects//elysian//pics//background.png");
        DrawTexture(background, 0, 0, WHITE);

        //DrawTexture(duck,100,100,WHITE);

        if(UntakenVills == -1) {
            DrawText("YOU WIN!", 500, 400, 200, DARKPURPLE);
            EndDrawing();
            WaitTime(3);
            endGame = false;
        }


        //ClearBackground(RAYWHITE);
        //draw table
        drawGrid();
        //DrawText("Elysian!", 850, 20, 80, DARKBLUE);



        //Draw the icons in the main window
        if(Round % 2 != 0){ //.............................. k1 ..................................
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m ; j++){
                    if(map1[i][j] == 'c'){
                        drawCastle1(i, j);
                    }
                    else if(map1[i][j] == 'b'){
                        drawCastle2(i, j);
                    }
                    else if(map1[i][j] == 'v'){
                        drawVillage(i, j);
                    }
                    else if(map1[i][j] == 'x'){
                        drawBlock(i, j);
                    }
                    else if(map1[i][j] == 'r'){
                        DrawRectangle(startX + j * cellSize, startY + i * cellSize, cellSize - 2, cellSize - 2, DARKBLUE);
                    }
                    else if(map1[i][j] == 'R'){
                        DrawRectangle(startX + j * cellSize, startY + i * cellSize, cellSize - 2, cellSize - 2, DARKPURPLE);
                    }
                    else{
                        Color level1 = (Color){0, 146, 115, 16};
                        Color level2 = (Color){0, 146, 115, 32};
                        Color level3 = (Color){0, 146, 115, 64};
                        Color level4 = (Color){0, 146, 115, 128};
                        Color level5 = (Color){0, 146, 115, 255};
                        if(map1[i][j]== 1){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level1);
                        }
                        else if(map1[i][j]== 2){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level2);
                        }
                        else if(map1[i][j]== 3){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level3);
                        }
                        else if(map1[i][j]== 4){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level4);
                        }
                        else if(map1[i][j]== 5){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level5);
                        }
                    }
                }
            }
        }
        else {  //.......................................... k2 ..........................................
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m ; j++){
                    if(map2[i][j] == 'c'){
                        drawCastle1(i, j);
                    }
                    else if(map2[i][j] == 'b'){
                        drawCastle2(i, j);
                    }
                    else if(map2[i][j] == 'v'){
                        drawVillage(i, j);
                    }
                    else if(map2[i][j] == 'x'){
                        drawBlock(i, j);
                    }
                    else if(map2[i][j] == 'r'){
                        DrawRectangle(startX + j * cellSize, startY + i * cellSize, cellSize - 2, cellSize - 2, DARKBLUE);
                    }
                    else if(map2[i][j] == 'R'){
                        DrawRectangle(startX + j * cellSize, startY + i * cellSize, cellSize - 2, cellSize - 2, DARKPURPLE);
                    }
                    else{
                        Color level1 = (Color){0, 146, 115, 16};
                        Color level2 = (Color){0, 146, 115, 32};
                        Color level3 = (Color){0, 146, 115, 64};
                        Color level4 = (Color){0, 146, 115, 128};
                        Color level5 = (Color){0, 146, 115, 255};
                        if(map2[i][j]== 1){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level1);
                        }
                        else if(map2[i][j]== 2){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level2);
                        }
                        else if(map2[i][j]== 3){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level3);
                        }
                        else if(map2[i][j]== 4){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level4);
                        }
                        else if(map2[i][j]== 5){
                            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize-2, cellSize-2, level5);
                        }
                    }
                }
            }
        }


        drawInformation();  //define in info.c


        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            //way(); // for Faz 4 we will add a MOUSE_BUTTON_RIGHT for second castle
            if(Way()){
                update();
                Round++;
            }
            else{
                DrawText("You can't make road here!", 650, 820, 40, RED);
                EndDrawing();
                WaitTime(2);
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




        EndDrawing();
    }



    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}