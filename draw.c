#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int maxRow = 17;
const int maxCol = 17;

int n; //Number of Rows
int m; //Number of Column
int map[17][17] = {0};
int villNum; //Number of villages
int castleNum;
int startX;
int startY;

const int windowSize=1050;
const int cellSize=50;

// OUR Lovely STRUCTS:
typedef struct{
    int x;
    int y;
}Point;

void drawGrid() {
    Texture2D background = LoadTexture("D://git projects//elysian//pics//background.png");
    DrawTexture(background, 0, 0, WHITE);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            //DrawRectangle(startX + j * cellSize, startY + i * cellSize, cellSize, cellSize, LIGHTGRAY);
            DrawRectangleLines(startX + j * cellSize, startY + i * cellSize, cellSize, cellSize, DARKGRAY);
        }
    }
}
void generate_random(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] != 'c' && map[i][j] != 'v' && map[i][j] != 'b' && map[i][j] != 'x'){
                map[i][j]= GetRandomValue(1,5);
            }
        }
    }
}

void drawCastle1(int y, int x) {
    Texture2D castle= LoadTexture("D://git projects//elysian//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, PURPLE);
}
void drawCastle2(int y, int x) {
    Texture2D castle= LoadTexture("D://git projects//elysian//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, PURPLE);
}
void drawVillage(int y, int x){
    Texture2D village = LoadTexture("D://git projects//elysian//pics//village.png");
    DrawTexture(village, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawBlock(int y, int x){
    Texture2D block = LoadTexture("D://git projects//elysian//pics//block.png");
    DrawTexture(block, startX + x * cellSize, startY + y * cellSize, WHITE);
}

void Map() {
    startX = (windowSize - (m * cellSize)) / 2 + 400;
    startY = (windowSize - (n * cellSize)) / 2;

    printf("number of castles(1 or 2): ");
    int castle1, castle2;
    scanf("%d", &castleNum);                //get the number of castles
    int x1, y1, x2, y2;
    if (castleNum == 1) {
        printf("castle 1 coordinations(x1, y1): ");        //get castles coordinates
        scanf("%d %d", &x1, &y1);
    } else {
        printf("castle 1 coordinations(x1, y1): ");
        printf("x1 y1 = ");
        scanf("%d %d", &x1, &y1);
        printf("castle 2 coordinations(x2, y2): ");
        printf("x2 y2= ");
        scanf("%d %d", &x2, &y2);
    }
    printf("Enter the number of village(max = 25): ");

    scanf("%d", &villNum);
    for (int i = 0; i < villNum; i++) {
        int x, y;
        printf("Enter the coordination of village number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        map[x - 1][y - 1] = 'v';
    }
    int gold[25], food[25];
    for (int i = 0; i < villNum; i++) {
        printf("Enter the gold and food for village number %d: ", i + 1);
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
            else if(i + 1 == x2 && j + 1 == y2){
                //printf("c2 ");
                map[i][j] = 'b';
            }
            else if (map[i][j] == 0) {
                //printf(" 1 ");
                map[i][j] = 1;
            }
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf(" %d ", map[i][j]);
        }
        printf("\n");
    }
}

void way(){
    int x, y;
    Vector2 mousePos = GetMousePosition();
    x = (mousePos.x-startX)/50;
    y = (mousePos.y-startY)/50;
    map[x][y] = 'r';
}