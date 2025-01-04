#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "info.h"
#include <stdbool.h>
#include <unistd.h>




const int maxRow = 17;
const int maxCol = 17;

int n; //Number of Rows
int m; //Number of Column
int map[17][17] = {0};
int villNum; //Number of villages
int castleNum;
int startX;
int startY;
int UntakenVills;

int Round = 1;

kingdom k1, k2;
village v[25];

const int windowSize=1050;
const int cellSize=50;

void drawGrid() {
    /*Texture2D background = LoadTexture("D://git projects//elysian//pics//background.png");
    DrawTexture(background, 0, 0, WHITE);*/
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
            if(map[i][j] == 0){
                map[i][j]= GetRandomValue(1,5);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            printf(" %d ",map[i][j]);
        }
        printf("\n");
    }
}

void drawCastle1(int y, int x) {
    Texture2D castle= LoadTexture("D://git projects//elysian//pics//castle2.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, DARKBLUE);
}
void drawCastle2(int y, int x) {
    Texture2D castle= LoadTexture("D://git projects//elysian//pics//castle2.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, DARKPURPLE);
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

    k1.gold = 5;
    k1.worker = 1;
    k1.food = 0;
    k1.soldier = 0;
    k1.goldProduction = 1;
    k1.foodProduction = 0;
    k1.roadCount = 0;

    k2.gold = 5;
    k2.worker = 1;
    k2.food = 0;
    k2.soldier = 0;
    k2.goldProduction = 1;
    k2.foodProduction = 0;
    k2.roadCount = 0;
    k2.x = k2.y = -1;

    printf("number of castles(1 or 2): ");
    int castle1, castle2;
    scanf("%d", &castleNum);                //get the number of castles
    int x1, y1, x2, y2;
    if (castleNum == 1) {
        printf("castle 1 coordinations(x1, y1): ");        //get castles coordinates
        scanf("%d %d", &x1, &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
    } else {
        printf("castle 1 coordinations(x1, y1): ");
        scanf("%d %d", &x1, &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
        printf("castle 2 coordinations(x2, y2): ");
        scanf("%d %d", &x2, &y2);
        while(x2 == x1 && y2 == y1){
            printf("castle 2 coordinations(x2, y2): ");
            scanf("%d %d", &x2, &y2);
        }
        k2.x = x2 - 1;
        k2.y = y2 - 1;
    }
    printf("Enter the number of village(max = 25): ");
    scanf("%d", &villNum);
    UntakenVills = villNum;
    for (int i = 0; i < villNum; i++) {
        int x, y;
        printf("Enter the coordination of village number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        x--;
        y--;
        bool flag = true;
        if (x == k1.x && y == k1.y || x == k2.x && y == k2.y) {
            flag = false;
        }
        for (int j = i - 1; j >=0  ; j--) {
            if (x == v[j].x && y == v[j].y) {
                flag = false;
                break;
            }
        }
        while (!flag) {
            printf("Enter the coordination of village number %d: ", i + 1);
            scanf("%d %d", &x, &y);
            x--;
            y--;
            flag = true;
            if (x == k1.x && y == k1.y || x == k2.x && y == k2.y) {
                flag = false;
                continue;
            }
            for (int j = i - 1; j >= 0 ; j--) {
                if (x == v[j].x && y == v[j].y) {
                    flag = false;
                    break;
                }
            }
        }
        map[x][y] = 'v';
        v[i].x = x;
        v[i].y = y;
        v[i].free = true;
    }

    for (int i = 0; i < villNum; i++) {
        printf("Enter the gold and food for village number %d: ", i + 1);
        scanf("%d %d", &v[i].goldRate, &v[i].foodRate);
    }

    printf("Enter the number of block: ");
    int blockNum;
    scanf("%d", &blockNum);
    for (int i = 0; i < blockNum; i++) {
        int x, y;
        printf("Enter the coordanation of block number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        x--;
        y--;
        bool flag = true; // input is write

        // check if the input is not write?
        if(x == k1.x && y == k1.y || x == k2.x && y == k2.y){
            flag = false;
        }
        for(int j = 0; j < villNum; j++){
            if(x == v[j].x && y == v[j].y){
                flag = false;
                break;
            }
        }
        while(!flag){
            printf("Enter the coordanation of block number %d: ", i + 1);
            scanf("%d %d", &x, &y);
            x--;
            y--;
            flag = true;
            if(x == k1.x && y == k1.y || x == k2.x && y == k2.y){
                flag = false;
                continue;
            }
            for(int j = 0; j < villNum; j++){
                if(x == v[j].x && y == v[j].y){
                    flag = false;
                    break;
                }
            }
        }
        map[x][y] = 'x';
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 == x1 && j + 1 == y1) {
                map[i][j] = 'c';
            }
            else if(i + 1 == x2 && j + 1 == y2){
                map[i][j] = 'b';
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

void wayCheck(int x,int y){
    if(map[x][y]=='r'){
        if(map[x-1][y]=='v' || map[x+1][y]=='v' || map[x][y-1]=='v' || map[x][y+1]=='v'){
            for(int i=0;i<villNum;i++){
                if((x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x ) && v[i].free != false){
                    v[i].free = false;
                    UntakenVills -= 1;
                    k1.goldProduction += v[i].goldRate;
                    k1.foodProduction += v[i].foodRate;
                }
            }
        }
    }
}
bool Way(){
    int x, y;
    Vector2 mousePos = GetMousePosition();
    y = (mousePos.x-startX)/50;
    x = (mousePos.y-startY)/50;
    if(x == k1.x + 1 && y == k1.y || x == k1.x && y == k1.y + 1 || x == k1.x - 1 && y == k1.y || x == k1.x && y == k1.y - 1
       || map[x][y-1] == 'r' || map[x-1][y] == 'r' || map[x+1][y] == 'r' || map[x][y+1] == 'r'){
        if(map[x][y] != 'x' && map[x][y] != 'v' && map[x][y] != 'c' && map[x][y] != 'b'){
            if(k1.worker >= map[x][y]){
                k1.road[k1.roadCount].x = x;
                k1.road[k1.roadCount].y = y;
                k1.roadCount++;
                //k1.worker -= map[x][y];
                map[x][y] = 'r';
                wayCheck(x, y);
            }
            else if(map[x][y] != 'r'){
                map[x][y] -= k1.worker;
            }
            return true;
        }
    }

    return false;
}

void drawInformation(int Round) {

    //..........................  Round Counter .....................................................
    char RoundS[5];
    sprintf(RoundS, "%d", Round);  // Convert int to string
    DrawText("Round: ", 800, 20, 40, DARKBLUE);
    DrawText(RoundS, 950, 20, 40, DARKBLUE);
    //................................................................................................

    //.......................... kingdom 1 information ...............................................
    char s[5];
    sprintf(s, "%d", k1.food);
    DrawText("k1.food: ", 10, 200, 40, DARKBLUE);
    DrawText(s, 210, 200, 40, DARKBLUE);

    sprintf(s, "%d", k1.gold);
    DrawText("k1.gold: ", 10, 300, 40, DARKBLUE);
    DrawText(s, 210, 300, 40, DARKBLUE);

    sprintf(s, "%d", k1.worker);
    DrawText("k1.worker: ", 10, 400, 40, DARKBLUE);
    DrawText(s, 210, 400, 40, DARKBLUE);

    sprintf(s, "%d", k1.soldier);
    DrawText("k1.soldier: ", 10, 500, 40, DARKBLUE);
    DrawText(s, 210, 500, 40, DARKBLUE);

    sprintf(s, "%d", k1.goldProduction);
    DrawText("k1.gold Production: ", 10, 600, 40, DARKBLUE);
    DrawText(s, 390, 600, 40, DARKBLUE);

    sprintf(s, "%d", k1.foodProduction);
    DrawText("k1.food Production: ", 10, 700, 40, DARKBLUE);
    DrawText(s, 400, 700, 40, DARKBLUE);
    //.................................................................................................


    //.....................................  Round Guide  ..............................................
    DrawText("key 1  >> buyFood ", 1600, 60, 30, DARKBLUE);
    DrawText("key 2 >> getWorker ", 1600, 90, 30, DARKBLUE);
    DrawText("key 3 >> getSoldier ", 1600, 120, 30, DARKBLUE);
    DrawText("click on the cell you want >> makeRoad", 1300, 30, 30, DARKBLUE);
    DrawText("key 4 >> doNothing ", 1600, 150, 30, DARKBLUE);
    //...................................................................................................

    //....................... Color introduction (difficulty level) .....................................
    Color level1 = (Color){0, 146, 115, 16};
    Color level2 = (Color){0, 146, 115, 32};
    Color level3 = (Color){0, 146, 115, 64};
    Color level4 = (Color){0, 146, 115, 128};
    Color level5 = (Color){0, 146, 115, 255};
    DrawText("Hardest", 1550, 450, 30, DARKBLUE);
    DrawRectangle(1600, 520, cellSize-2, cellSize-2, level5);
    DrawRectangle(1600, 570, cellSize-2, cellSize-2, level4);
    DrawRectangle(1600, 620, cellSize-2, cellSize-2, level3);
    DrawRectangle(1600, 670, cellSize-2, cellSize-2, level2);
    DrawRectangle(1600, 720, cellSize-2, cellSize-2, level1);
    DrawText("Easiest", 1550, 770, 30, DARKBLUE);
    DrawText("Number of\nneeded workers", 1700, 450, 27, DARKBLUE);
    DrawText(" --->  5", 1650, 520, 30, DARKBLUE);
    DrawText(" --->  4", 1650, 570, 30, DARKBLUE);
    DrawText(" --->  3", 1650, 620, 30, DARKBLUE);
    DrawText(" --->  2", 1650, 670, 30, DARKBLUE);
    DrawText(" --->  1", 1650, 720, 30, DARKBLUE);
    //................................................................................................
}