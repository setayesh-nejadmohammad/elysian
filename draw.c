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
void Map(int map[][17],int n,int m){
    printf("number of castles(1 or 2): ");
    int castleNum, castle1, castle2;
    scanf("%d", &castleNum);                //get the number of castles
    int x1, y1, x2, y2;
    if (castleNum == 1) {
        printf("castle 1 coordinations(x1, y1): ");        //get castles coordinates
        scanf("%d %d", &x1, &y1);
    } else {
        printf("castle 1 coordinations(x1, y1): ");
        scanf("%d %d", &x1, &y1);
        printf("castle 2 coordinations(x2, y2): ");
        scanf("%d %d", &x2, &y2);
    }
    printf("Enter the number of village(max = 20): ");
    int villNum;
    scanf("%d", &villNum);
    for (int i = 0; i < villNum; i++) {
        int x, y;
        printf("Enter the coordination of village number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = 'v';
    }
    int gold[20], food[20];
    for (int i = 0; i < villNum; i++) {
        printf("Enter the amount gold and food for village number %d: ", i + 1);
        scanf("%d %d", &gold[i], &food[i]);
    }
    printf("Enter the number of block: ");
    int blockNum;
    scanf("%d", &blockNum);
    for (int i = 0; i < blockNum; i++) {
        int x, y;
        printf("Enter the coordanation of block number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = 'x';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 == x1 && j + 1 == y1) {
                //printf("c1 ");
                map[i][j] = 'c';
            }
                /*else if(i == x2 && j == y2){
                    printf("c2 ");
                    map[i][j] = 'b';
                }*/
            else if (map[i][j] == 0) {
                //printf(" 1 ");
                map[i][j] = 1;
            }
        }
    }
}
