#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "info.h"


const int maxRow = 17;
const int maxCol = 17;

int n; //Number of Rows
int m; //Number of Column
int map[17][17] = {0};
int villNum; //Number of villages
int castleNum;
int startX;
int startY;

kingdom k1, k2;
village v[25];

const int windowSize=1824;
const int cellSize=50;

// OUR Lovely STRUCTS:
typedef struct{
    int x;
    int y;
}Point;

void drawGrid() {
    Texture2D background = LoadTexture("D://projects//elysian2//pics//11zon_resized.png");
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
    Texture2D castle= LoadTexture("D://projects//elysian2//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, BLACK);
}
void drawCastle2(int y, int x) {
    Texture2D castle= LoadTexture("D://projects//elysian2//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, PURPLE);
}
void drawVillage(int y, int x){
    Texture2D village = LoadTexture("D://projects//elysian2//pics//village.png");
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

    k2.gold = 5;
    k2.worker = 1;
    k2.food = 0;
    k2.soldier = 0;
    k2.goldProduction = 1;
    k2.foodProduction = 0;

    printf("number of castles(1 or 2): ");
    int castle1, castle2;
    scanf("%d", &castleNum);                //get the number of castles
    int x1 =0 , y1 = 0, x2 = 0, y2 = 0;
    if(castleNum == 1) {
        printf("castle 1 coordinations(x1, y1): ");        //get castles coordinates
        scanf("%d %d", &x1, &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
    }
    if(castleNum == 2) {
        printf("castle 1 coordinations(x1, y1): ");
        scanf("%d %d", &x1, &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
        printf("castle 2 coordinations(x2, y2): ");
        scanf("%d %d", &x2, &y2);
        while(x1==x2 && y1==y2) {
            printf("castle 2 coordinations(x2, y2): ");
            scanf("%d %d", &x2, &y2);
        }
        k2.x = x2 - 1;
        k2.y = y2 - 1;
    }

    printf("Enter the number of village(max = 25): ");
    scanf("%d", &villNum);
    for (int i = 0; i < villNum; i++) {
        int x, y;
        printf("Enter the coordination of village number %d: ", i + 1);
        scanf("%d %d", &x, &y);
        x--;
        y--;
        bool flag = true;
        if (x == k1.x && y == k1.y | x == k2.x && y == k2.y) {
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
            if (x == k1.x && y == k1.y | x == k2.x && y == k2.y) {
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

        map[x - 1][y - 1] = 'x';
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 == x1 && j + 1 == y1) {
                map[i][j] = 'c';
            }
            else if(i + 1 == x2 && j + 1 == y2){
                map[i][j] = 'b';
            }
            else if (map[i][j] == 0) {
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
void wayCheck(int x,int y){
    if(map[x][y]=='r'){
        if(map[x-1][y]=='v' || map[x+1][y]=='v' || map[x][y-1]=='v' || map[x][y+1]=='v'){
            for(int i=0;i<villNum;i++){
                if(x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x){
                    v[i].free = false;
                    k1.goldProduction += v[i].goldRate;
                    k1.foodProduction += v[i].foodRate;
                }
            }
        }
    }
}
void way(){
    int x, y;
    Vector2 mousePos = GetMousePosition();
    y = (mousePos.x-startX)/50;
    x = (mousePos.y-startY)/50;
    if(map[x][y]!='x' && map[x][y]!='v' && map[x][y]!='b' && map[x][y]!='c'){
        if(k1.worker >= map[x][y]){
            map[x][y] = 'r';
            wayCheck(x,y);
        }
        else{
            map[x][y] -= k1.worker;
            DrawText("You don't have enough worker!",1000,20,40,RED);
        }
    }
}

void drawInformation(int Round){
    char RoundS[5];
    sprintf(RoundS, "%d", Round);  // Convert int to string

    DrawText("Round: ", 800, 20, 40, DARKBLUE);
    DrawText(RoundS, 950, 20, 40, DARKBLUE);
    //DrawTexture(RoundGuide, 1500, 400, WHITE);


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
    }