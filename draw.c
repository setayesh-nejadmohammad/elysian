#include "raylib.h"
#include <stdio.h>

const int windowSize=800;
const int cellSize=40;

void drawGrid(int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, LIGHTGRAY);
            DrawRectangleLines(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, DARKGRAY);
        }
    }
}
void drawColor(int x, int y, int n, int m){    //x and y are chosen by user and this function will change the color of that position.
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    DrawRectangle(startX + x*cellSize, startY + y*cellSize, cellSize-2, cellSize-2, RED);
}
void drawCastle(int x, int y, int n, int m) {
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D castle= LoadTexture("C://Users//M//CLionProjects//elysian1//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawVillage(int x, int y, int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D village = LoadTexture("D://git projects//elysian//pics//village.png");
    DrawTexture(village, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawBlock(int x, int y, int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D block = LoadTexture("C://Users//M//CLionProjects//elysian1//pics//blouk (2).png");
    DrawTexture(block, startX + x * cellSize, startY + y * cellSize, WHITE);
}
