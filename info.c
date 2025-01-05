#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "info.h"


void update(){
    k1.gold += k1.goldProduction;
    k1.food += k1.foodProduction;

    k2.gold += k2.goldProduction;
    k2.food += k2.foodProduction;
}

void buyFood(){
    if(Round % 2 != 0){
        if(k1.gold>=1){
            k1.food++;
            k1.gold--;
        }
    }
    else if( Round % 2 == 0) {
        if (k2.gold >= 1) {
            k2.food++;
            k2.gold--;
        }
    }
}
void getWorker(){
    if( Round % 2 != 0){
        if(k1.food>=3){
            k1.food=(k1.food)-3;
            k1.worker++;
        }
    }
    else if(Round % 2 == 0){
        if(k2.food>=3){
            k2.food=(k2.food)-3;
            k2.worker++;
        }
    }
}
void getSoldier(){
    if(Round % 2 != 0){
        if(k1.gold>=2){
            k1.gold -= 2;
            k1.soldier++;
        }
    }
    else if( Round % 2 == 0){
        if(k2.gold>=2){
            k2.gold -= 2;
            k2.soldier++;
        }
    }
}
void drawInformation() {
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
    DrawText("Hardest", 2250, 760, 30, DARKBLUE);
    DrawRectangle(2350, 810, cellSize-2, cellSize-2, level5);
    DrawRectangle(2350, 860, cellSize-2, cellSize-2, level4);
    DrawRectangle(2350, 910, cellSize-2, cellSize-2, level3);
    DrawRectangle(2350, 960, cellSize-2, cellSize-2, level2);
    DrawRectangle(2350, 1010, cellSize-2, cellSize-2, level1);
    DrawText("Easiest", 2250, 1070, 30, DARKBLUE);
    DrawText("Number of needed workers", 2450, 750, 27, DARKBLUE);
    DrawText(" --->  5", 2450, 810, 30, DARKBLUE);
    DrawText(" --->  4", 2450, 860, 30, DARKBLUE);
    DrawText(" --->  3", 2450, 910, 30, DARKBLUE);
    DrawText(" --->  2", 2450, 960, 30, DARKBLUE);
    DrawText(" --->  1", 2450, 1010, 30, DARKBLUE);
    //................................................................................................
}