#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "info.h"
#include <stdbool.h>




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

int Round = 1 ;

kingdom k1, k2;
village v[25];

const int windowSize=1824;
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
    Texture2D castle= LoadTexture("D://projects//elysian2//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, BLACK);
}
void drawCastle2(int y, int x) {
    Texture2D castle= LoadTexture("D://projects//elysian2//pics//castle2.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, PURPLE);
}
void drawVillage(int y, int x){
    Texture2D village = LoadTexture("D://projects//elysian2//pics//village.png");
    DrawTexture(village, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawBlock(int y, int x){
    Texture2D block = LoadTexture("D://projects//elysian2//pics//block.png");
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
    k1.Villnum = 0;

    k2.gold = 5;
    k2.worker = 1;
    k2.food = 0;
    k2.soldier = 0;
    k2.goldProduction = 1;
    k2.foodProduction = 0;
    k2.roadCount = 0;
    k2.Villnum = 0;
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

bool war(int x,int y){
    int state = -1 ;
    if(Round % 2 != 0 ){
        if(map1[x][y-1] == 'R' || map1[x][y+1] == 'R' || map1[x-1][y] == 'R' || map1[x+1][y] == 'R'){
            if(k1.worker == k2.worker){
                state = 0;
            }
            else if(k1.worker > k2.worker){
                state = 1;
            }
            else if(k1.worker < k2.worker){
                state = 2;
            }
            return true ;
        }
          else {
              return false;
          }
    }
    if(Round % 2 == 0 ){
        if(map2[x][y-1] == 'r' || map2[x][y+1] == 'r' || map2[x-1][y] == 'r' || map[x+1][y] == 'r'){

            if(k1.worker == k2.worker){
                state = 0;
            }
            else if(k1.worker > k2.worker){
                state = 1;
            }
            else if(k1.worker < k2.worker){
                state = 2;
            }
            return true;
        }
        else{
            return false;
        }
    }
    if(Round % 2 != 0){
        for(int i = 0 ; i<villNum ; i++){
            if(x-1 == v[k1.vills[i]].x && y == v[k1.vills[i]].y || x == v[k1.vills[i]].x && y-1 == v[k1.vills[i]].y || x+1 == v[k1.vills[i]].x && y == v[k1.vills[i]].y)
        }
    }
}
void wayCheck(int x,int y){
    if(map[x][y]=='r'){
        if(map[x-1][y]=='v' || map[x+1][y]=='v' || map[x][y-1]=='v' || map[x][y+1]=='v'){
            for(int i=0;i<villNum;i++){
                if((x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x ) && v[i].free != false){
                    v[i].free = false;
                    k1.vills[i] = i;
                    k1.villnum++;
                    UntakenVills -= 1;
                    k1.goldProduction += v[i].goldRate;
                    k1.foodProduction += v[i].foodRate;
                }
            }
        }
    }
    if(map[x][y]=='R'){
        if(map[x-1][y]=='v' || map[x+1][y]=='v' || map[x][y-1]=='v' || map[x][y+1]=='v'){
            for(int i=0;i<villNum;i++){
                if((x-1==v[i].x && y==v[i].y || x+1==v[i].x && y==v[i].y || x==v[i].x && y-1==v[i].y || y+1==v[i].y && x==v[i].x ) && v[i].free != false){
                    v[i].free = false;
                    k2.vills[i] = i;
                    k2.villnum++;
                    UntakenVills -= 1;
                    k2.goldProduction += v[i].goldRate;
                    k2.foodProduction += v[i].foodRate;
                }
            }
        }
    }
}
bool Way() {
    int x, y;
    Vector2 mousePos = GetMousePosition();
    y = (mousePos.x - startX) / 50;
    x = (mousePos.y - startY) / 50;

    if (Round % 2 != 0) {

        bool warDone = false;
        if(war(x,y)){
            warDone = true;
        }

        bool flag = false;
        for(int i=0 ; i< k1.villnum ; i++){
            if(x-1 == v[k1.vills[i]].x && y == v[k1.vills[i]].y || x == v[k1.vills[i]].x && y-1 == v[k1.vills[i]].y || x+1 == v[k1.vills[i]].x && y == v[k1.vills[i]].y || x == v[k1.vills[i]].x && y+1 == v[k1.vills[i]].y){
                flag = true;
                break;
            }
        }
        if ((x == k1.x + 1 && y == k1.y || x == k1.x && y == k1.y + 1 || x == k1.x - 1 && y == k1.y || x == k1.x && y == k1.y - 1 || map[x][y - 1] == 'r' || map[x - 1][y] == 'r' || map[x + 1][y] == 'r' || map[x][y + 1] == 'r' || flag) && !warDone) {
            if (map[x][y] != 'x' && map[x][y] != 'v' && map[x][y] != 'c' && map[x][y] != 'b') {
                if (k1.worker >= map[x][y]) {
                    k1.road[k1.roadCount].x = x;
                    k1.road[k1.roadCount].y = y;
                    k1.roadCount++;
                    map[x][y] = 'r';
                    wayCheck(x, y);
                } else if (map[x][y] != 'r') {
                    map[x][y] -= k1.worker;
                }
                return true;
            }
        }
        return false;
    }
    else if (Round % 2 == 0) {

        bool warDone = false;
        if(war(x,y)){
            warDone = true;
        }

        bool flag = false;
        for(int i=0 ; i< k2.villnum ; i++){
            if(x-1 == v[k2.vills[i]].x && y == v[k2.vills[i]].y || x == v[k2.vills[i]].x && y-1 == v[k2.vills[i]].y || x+1 == v[k2.vills[i]].x && y == v[k2.vills[i]].y || x == v[k2.vills[i]].x && y+1 == v[k2.vills[i]].y){
                flag = true;
                break;
            }
        }
        if ((x == k2.x + 1 && y == k2.y || x == k2.x && y == k2.y + 1 || x == k2.x - 1 && y == k2.y ||
            x == k2.x && y == k2.y - 1
            || map[x][y - 1] == 'R' || map[x - 1][y] == 'R' || map[x + 1][y] == 'R' || map[x][y + 1] == 'R' || flag) && !warDone) {
            if (map[x][y] != 'x' && map[x][y] != 'v' && map[x][y] != 'c' && map[x][y] != 'b') {
                if (k2.worker >= map[x][y]) {
                    k2.road[k2.roadCount].x = x;
                    k2.road[k2.roadCount].y = y;
                    k2.roadCount++;
                    map[x][y] = 'R';
                    wayCheck(x, y);
                } else if (map[x][y] != 'R') {
                    map[x][y] -= k2.worker;
                }
                return true;
            }
        }
        return false;
    }
}

