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

int map[17][17] = {0};  //main map
int map1[17][17] = {0}; //k1 map
int map2[17][17] = {0}; //k2 map

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
    k1.villNum = 0;


    k2.gold = 5;
    k2.worker = 1;
    k2.food = 0;
    k2.soldier = 0;
    k2.goldProduction = 1;
    k2.foodProduction = 0;
    k2.roadCount = 0;
    k2.x = k2.y = -1;
    k2.villNum = 0;

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

void roadClear(int x, int y, int state){ // state shows that which Kingdom won the war
    int rCount = 0; // number of road around the first road
    if(map1[x-1][y] == 'r'){
        rCount++;
    }
    if(map1[x][y-1] == 'r'){
        rCount++;
    }
    if(map1[x+1][y] == 'r'){
        rCount++;
    }
    if(map1[x][y+1] == 'r'){
        rCount++;
    }
    if(rCount > 1){
        map1[x][y] = map[x][y];  //remove the road from map1
    }
}

void wayCheck(int x,int y){
    if(Round % 2 != 0){   //k1
        if(map1[x][y]=='r'){
            if(map1[x-1][y]=='v' || map1[x+1][y]=='v' || map1[x][y-1]=='v' || map1[x][y+1]=='v'){
                for(int i=0;i<villNum;i++){
                    if((x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x ) && v[i].free != false){
                        v[i].free = false;
                        k1.vills[i] = i;
                        k1.villNum ++;
                        UntakenVills -= 1;
                        k1.goldProduction += v[i].goldRate;
                        k1.foodProduction += v[i].foodRate;
                    }
                }
            }
        }
    }
    else{   //k2
        if(map2[x][y]=='R'){
            if(map2[x-1][y]=='v' || map2[x+1][y]=='v' || map2[x][y-1]=='v' || map2[x][y+1]=='v'){
                for(int i=0;i<villNum;i++){
                    if((x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x ) && v[i].free != false){
                        v[i].free = false;
                        k2.vills[i] = i;
                        k2.villNum ++;
                        UntakenVills -= 1;
                        k2.goldProduction += v[i].goldRate;
                        k2.foodProduction += v[i].foodRate;
                    }
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
    if(Round % 2 != 0){    //k1 way
        bool flag = false;
        for(int i = 0; i < k1.villNum; i++){
            if(x-1==v[k1.vills[i]].x && y==v[k1.vills[i]].y || x+1==v[k1.vills[i]].x && y==v[k1.vills[i]].y || x==v[k1.vills[i]].x && y-1==v[k1.vills[i]].y || y+1==v[k1.vills[i]].y && x==v[k1.vills[i]].x ){
                flag = true;
                break;
            }
        }
        if(x == k1.x + 1 && y == k1.y || x == k1.x && y == k1.y + 1 || x == k1.x - 1 && y == k1.y || x == k1.x && y == k1.y - 1
           || map1[x][y-1] == 'r' || map1[x-1][y] == 'r' || map1[x+1][y] == 'r' || map1[x][y+1] == 'r' || flag){
            if(map1[x][y] != 'x' && map1[x][y] != 'v' && map1[x][y] != 'c' && map1[x][y] != 'b' && map1[x][y] != 'R'){
                if(k1.worker >= map1[x][y]){
                    k1.road[k1.roadCount].x = x;
                    k1.road[k1.roadCount].y = y;
                    k1.roadCount++;
                    map1[x][y] = 'r';
                    map2[x][y] = 'r';
                    wayCheck(x, y);
                }
                else if(map1[x][y] != 'r'){
                    map1[x][y] -= k1.worker;
                }
                return true;
            }
        }

        return false;
    }
    else{     //k2 way
        bool flag = false;
        for(int i = 0; i < k2.villNum; i++){
            if(x-1==v[k2.vills[i]].x && y==v[k2.vills[i]].y || x+1==v[k2.vills[i]].x && y==v[k2.vills[i]].y || x==v[k2.vills[i]].x && y-1==v[k2.vills[i]].y || y+1==v[k2.vills[i]].y && x==v[k2.vills[i]].x ){
                flag = true;
                break;
            }
        }
        if(x == k2.x + 1 && y == k2.y || x == k2.x && y == k2.y + 1 || x == k2.x - 1 && y == k2.y || x == k2.x && y == k2.y - 1
           || map2[x][y-1] == 'R' || map2[x-1][y] == 'R' || map2[x+1][y] == 'R' || map2[x][y+1] == 'R' || flag){
            if(map2[x][y] != 'x' && map2[x][y] != 'v' && map2[x][y] != 'c' && map2[x][y] != 'b' && map2[x][y] != 'r'){
                if(k2.worker >= map2[x][y]){
                    k2.road[k2.roadCount].x = x;
                    k2.road[k2.roadCount].y = y;
                    k2.roadCount++;
                    map2[x][y] = 'R';
                    map1[x][y] = 'R';
                    wayCheck(x, y);
                }
                else if(map2[x][y] != 'R'){
                    map2[x][y] -= k2.worker;
                }
                return true;
            }
        }

        return false;
    }
}

