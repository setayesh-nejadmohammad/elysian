#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "info.h"
#include <stdbool.h>
#include <unistd.h>
#include "war.h"



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
int WhoWin; // if k1 win(WhoWin = 1) if k2 win(WhoWin = 2)

int Round = 1;

kingdom k1, k2;
village v[25];

const int windowSize=1050;
const int cellSize=50;

void drawGrid() {
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


void Map() {


    FILE *input;
    input = fopen("D://git projects//elysian//test.txt", "rt");

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

    /*printf("Enter the dimensions of the game:(it will be a n*m table)\n");
    printf("n = ");
    scanf("%d", &n); //get the table row num
    printf("m = ");
    scanf("%d", &m); //get the table column num
    */

    fscanf(input, "%d" , &n);
    fscanf(input, "%d" , &m);

    startX = (windowSize - (m * cellSize)) / 2 + 400;
    startY = (windowSize - (n * cellSize)) / 2;

    printf("number of castles(1 or 2): ");
    int castle1, castle2;
    //scanf("%d", &castleNum);                //get the number of castles
    fscanf(input, "%d" , &castleNum);
    int x1, y1, x2, y2;
    if (castleNum == 1) {
        printf("castle 1 coordinations(x1, y1): ");        //get castles coordinates
        //scanf("%d %d", &x1, &y1);
        fscanf(input, "%d" , &x1);
        fscanf(input, "%d" , &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
    } else {
        printf("castle 1 coordinations(x1, y1): ");
        //scanf("%d %d", &x1, &y1);
        fscanf(input, "%d" , &x1);
        fscanf(input, "%d" , &y1);
        k1.x = x1 - 1;
        k1.y = y1 - 1;
        printf("castle 2 coordinations(x2, y2): ");
        //scanf("%d %d", &x2, &y2);
        fscanf(input, "%d" , &x2);
        fscanf(input, "%d" , &y2);
        while(x2 == x1 && y2 == y1){
            printf("castle 2 coordinations(x2, y2): ");
            //scanf("%d %d", &x2, &y2);
        }
        k2.x = x2 - 1;
        k2.y = y2 - 1;
    }
    printf("Enter the number of village(max = 25): ");
    //scanf("%d", &villNum);
    fscanf(input, "%d" , &villNum);
    UntakenVills = villNum;
    for (int i = 0; i < villNum; i++) {
        int x, y;
        printf("Enter the coordination of village number %d: ", i + 1);
        //scanf("%d %d", &x, &y);
        fscanf(input, "%d" , &x);
        fscanf(input, "%d" , &y);
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
            //scanf("%d %d", &x, &y);
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
        //scanf("%d %d", &v[i].goldRate, &v[i].foodRate);
        fscanf(input, "%d" , &v[i].goldRate);
        fscanf(input, "%d" , &v[i].foodRate);
    }

    printf("Enter the number of block: ");
    int blockNum;
    //scanf("%d", &blockNum);
    fscanf(input, "%d" , &blockNum);
    for (int i = 0; i < blockNum; i++) {
        int x, y;
        printf("Enter the coordanation of block number %d: ", i + 1);
        //scanf("%d %d", &x, &y);
        fscanf(input, "%d" , &x);
        fscanf(input, "%d" , &y);
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
            //scanf("%d %d", &x, &y);
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
                        map1[v[i].x][v[i].y] = 'V';
                        map2[v[i].x][v[i].y] = 'V';
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
                        map1[v[i].x][v[i].y] = 'W';
                        map2[v[i].x][v[i].y] = 'W';
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

    int state = -1;
    if (k1.soldier > k2.soldier) {
        state = 1;
    } else if (k2.soldier > k1.soldier) {
        state = 2;
    } else if (k1.soldier == k2.soldier) {
        state = 0;
    }

    if(Round % 2 != 0){    //k1 way

        bool villCheck = false;
        if(map1[x][y-1] == 'V' || map2[x-1][y] == 'V' || map2[x+1][y] == 'V' || map2[x][y+1] == 'V') villCheck = true;

        bool kingdomCheck = false;
        if(x == k1.x + 1 && y == k1.y || x == k1.x && y == k1.y + 1 || x == k1.x - 1 && y == k1.y || x == k1.x && y == k1.y - 1) kingdomCheck = true;

        bool roadCheck = false;
        if(map1[x][y-1] == 'r' || map1[x-1][y] == 'r' || map1[x+1][y] == 'r' || map1[x][y+1] == 'r') roadCheck = true;

        bool Isk1Win = false; //in baraye ine ke vaghti ke ye jaee kenar jade harif mikhad jade bezane tarah nadashte bashe behesh natoone bezane.
        if(villCheck || kingdomCheck || roadCheck){
            if(war(x,y) && state == 1) Isk1Win = true;
            else if(war(x, y) && state == 2) return true;
            else if(!war(x, y)) Isk1Win = true;
        }

        villCheck = false;
        if(map1[x][y-1] == 'V' || map2[x-1][y] == 'V' || map2[x+1][y] == 'V' || map2[x][y+1] == 'V') villCheck = true;

        kingdomCheck = false;
        if(x == k1.x + 1 && y == k1.y || x == k1.x && y == k1.y + 1 || x == k1.x - 1 && y == k1.y || x == k1.x && y == k1.y - 1) kingdomCheck = true;

        roadCheck = false;
        if(map1[x][y-1] == 'r' || map1[x-1][y] == 'r' || map1[x+1][y] == 'r' || map1[x][y+1] == 'r') roadCheck = true;

        if((kingdomCheck || roadCheck || villCheck) && Isk1Win){
            if(map1[x][y] != 'x' && map1[x][y] != 'v' && map1[x][y] != 'c' && map1[x][y] != 'b' && map1[x][y] != 'R' && map1[x][y] != 'V' && map1[x][y] != 'W'){
                if(k1.worker >= map1[x][y]){
                    k1.road[k1.roadCount].x = x;
                    k1.road[k1.roadCount].y = y;
                    k1.roadCount++;
                    map1[x][y] = 'r';
                    map2[x][y] = 'r';
                    wayCheck(x, y);
                    //cleanTheWay(state);
                    return true;
                }
                else if(map1[x][y] != 'r') {
                    map1[x][y] -= k1.worker;
                    return true;
                }
            }
        }
        return false;
    }
    else{     //k2 way

        bool villCheck = false;
        if(map2[x][y-1] == 'W' || map2[x-1][y] == 'W' || map2[x+1][y] == 'W' || map2[x][y+1] == 'W') villCheck = true;

        bool kingdomCheck = false;
        if(x == k2.x + 1 && y == k2.y || x == k2.x && y == k2.y + 1 || x == k2.x - 1 && y == k2.y || x == k2.x && y == k2.y - 1) kingdomCheck = true;

        bool roadCheck = false;
        if(map2[x][y-1] == 'R' || map2[x-1][y] == 'R' || map2[x+1][y] == 'R' || map2[x][y+1] == 'R') roadCheck = true;

        bool Isk2Win = false;
        if(villCheck || kingdomCheck || roadCheck){
            if(war(x, y) && state == 2) Isk2Win = true;
            else if(war(x, y) && state == 1) return true;
            else if(!war(x, y)) Isk2Win = true;
        }

        villCheck = false;
        if(map2[x][y-1] == 'W' || map2[x-1][y] == 'W' || map2[x+1][y] == 'W' || map2[x][y+1] == 'W') villCheck = true;

        kingdomCheck = false;
        if(x == k2.x + 1 && y == k2.y || x == k2.x && y == k2.y + 1 || x == k2.x - 1 && y == k2.y || x == k2.x && y == k2.y - 1) kingdomCheck = true;

        roadCheck = false;
        if(map2[x][y-1] == 'R' || map2[x-1][y] == 'R' || map2[x+1][y] == 'R' || map2[x][y+1] == 'R') roadCheck = true;

        if((kingdomCheck || roadCheck || villCheck) && Isk2Win){
            if(map2[x][y] != 'x' && map2[x][y] != 'v' && map2[x][y] != 'c' && map2[x][y] != 'b' && map2[x][y] != 'r' && map2[x][y] != 'V' && map2[x][y] != 'W'){
                if(k2.worker >= map2[x][y]){
                    k2.road[k2.roadCount].x = x;
                    k2.road[k2.roadCount].y = y;
                    k2.roadCount++;
                    map2[x][y] = 'R';
                    map1[x][y] = 'R';
                    wayCheck(x, y);
                    //cleanTheWay(state);
                    return true;
                }
                else if(map2[x][y] != 'R'){
                    map2[x][y] -= k2.worker;
                    return true;
                }

            }
        }
        return false;
    }
}
