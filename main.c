#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "draw.h"
#include "info.h"
#include <string.h>

// in all the maps:
// v = not taken village
// V = taken village by k1
// W = taken village by k2

bool IsGameStarted = false;


int main(void) {
    //*********************************************************************************************************

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
    InitAudioDevice();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //Texture2D RoundGuide = LoadTexture("D:/git projects/elysian/pics/RoundGuide.png");
    Texture2D background = LoadTexture("D://git projects//elysian//pics//background.png");
    Texture2D block = LoadTexture("D://git projects//elysian//pics//block.png");
    Texture2D village = LoadTexture("D://git projects//elysian//pics//village2.png");
    Texture2D castle = LoadTexture("D://git projects//elysian//pics//castle2.png");
    Sound startSound = LoadSound("D://git projects//elysian//sounds//game start sound.mp3");
    Sound bubblepop = LoadSound("D://git projects//elysian//sounds//bubblepop.mp3");
    Sound funnyLose = LoadSound("D://git projects//elysian//sounds//funny lose.mp3");
    Sound gameOver = LoadSound("D://git projects//elysian//sounds//game over.mp3");
    Sound win = LoadSound("D://git projects//elysian//sounds//violin-win.mp3");
    Sound victory = LoadSound("D://git projects//elysian//sounds//victory.mp3");
    Music bgMusic = LoadMusicStream("D://git projects//elysian//sounds//background music.mp3");
    //--------------------------------------------------------------------------------------

    bool endGame = true;

    SetSoundVolume(gameOver, 5);
    SetSoundVolume(win, 3);
    SetMusicVolume(bgMusic, 1);
    SetSoundVolume(bubblepop, 9);
    SetSoundVolume(victory, 9);

    bool musicPlaying = false;
    PlayMusicStream(bgMusic);
    musicPlaying = true;

    // Main game loop
    while (!WindowShouldClose() && endGame)    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);
        IsSomeOneLost = false;
        State = -1;
        DrawTexture(background, 0, 0, WHITE);

        //DrawTexture(duck,100,100,WHITE);

        if(!IsGameStarted){
            DrawText("Elysian", 600, 400, 200, DARKPURPLE);
            IsGameStarted = true;
            EndDrawing();
            WaitTime(1.5);
            PlaySound(startSound);
        }

        if(UntakenVills == -1) {
            if(WhoWin == 1){
                DrawText("YOU WIN!", 500, 400, 200, DARKBLUE);
            }
            else if(WhoWin == 2){
                DrawText("YOU WIN!", 500, 400, 200, DARKPURPLE);
            }
            PlaySound(victory);
            EndDrawing();
            WaitTime(3);
            endGame = false;
        }

        UpdateMusicStream(bgMusic);
        if (IsKeyPressed(KEY_SPACE)) {
            musicPlaying = !musicPlaying;
            if (musicPlaying) {
                PlayMusicStream(bgMusic);
            } else {
                PauseMusicStream(bgMusic);
            }
        }

        DrawText("Press SPACE to on/off music", 1400, 1000, 20, DARKGRAY);
        // button to ON or OFF the background music
        Rectangle buttonRect = {startX / 2 + 1400, startY + 722, 160, 30};
        DrawRectangleRec(buttonRect, musicPlaying ? GREEN : RED);
        DrawText(musicPlaying ? "Music ON" : "Music OFF", buttonRect.x + 40, buttonRect.y + 5, 20, WHITE);


        //ClearBackground(RAYWHITE);
        //draw table
        drawGrid();
        //DrawText("Elysian!", 850, 20, 80, DARKBLUE);



        //Draw the icons in the main window
        if(Round % 2 != 0){ //.............................. k1 ..................................
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m ; j++){
                    if(map1[i][j] == 'c'){
                        //drawCastle1(i, j);
                        DrawTexture(castle, startX + j * cellSize, startY + i * cellSize, DARKBLUE);
                    }
                    else if(map1[i][j] == 'b'){
                        //drawCastle2(i, j);
                        DrawTexture(castle, startX + j * cellSize, startY + i * cellSize, DARKPURPLE);
                    }
                    else if(map1[i][j] == 'v'){
                        //drawVillage(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, BLACK);
                    }
                    else if(map1[i][j] == 'V'){
                        //drawVillage1(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, DARKBLUE);
                    }
                    else if(map1[i][j] == 'W'){
                        //drawVillage2(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, DARKPURPLE);
                    }
                    else if(map1[i][j] == 'x'){
                        //drawBlock(i, j);
                        DrawTexture(block, startX + j * cellSize, startY + i * cellSize, WHITE);
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
                        //drawCastle1(i, j);
                        DrawTexture(castle, startX + j * cellSize, startY + i * cellSize, DARKBLUE);
                    }
                    else if(map2[i][j] == 'b'){
                        //drawCastle2(i, j);
                        DrawTexture(castle, startX + j * cellSize, startY + i * cellSize, DARKPURPLE);
                    }
                    else if(map2[i][j] == 'v'){
                        //drawVillage(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, BLACK);
                    }
                    else if(map2[i][j] == 'V'){
                        //drawVillage1(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, DARKBLUE);
                    }
                    else if(map2[i][j] == 'W'){
                        //drawVillage2(i, j);
                        DrawTexture(village, startX + j * cellSize, startY + i * cellSize, DARKPURPLE);
                    }
                    else if(map2[i][j] == 'x'){
                        //drawBlock(i, j);
                        DrawTexture(block, startX + j * cellSize, startY + i * cellSize, WHITE);
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
            if(Way()){
                PlaySound(bubblepop);
                update();
                Round++;
            }
            else{
                PlaySound(gameOver);
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

        if(IsSomeOneLost && Round%2 != State%2 && State > 0){
            PlaySound(win);
        }
        else if(IsSomeOneLost){
            PlaySound(funnyLose);
        }




        EndDrawing();
    }


    UnloadSound(startSound);
    UnloadSound(gameOver);
    UnloadSound(bubblepop);
    UnloadSound(win);
    CloseAudioDevice();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}