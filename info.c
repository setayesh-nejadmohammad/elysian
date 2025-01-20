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
    if(Round % 2 != 0){  //k1
        if(k1.gold>=1){
            k1.food++;
            k1.gold--;
        }
    }
    else{                 //k2
        if(k2.gold>=1){
            k2.food++;
            k2.gold--;
        }
    }
}
void getWorker(){
    if(Round % 2 != 0){ //k1
        if(k1.food>=3){
            k1.food=(k1.food)-3;
            k1.worker++;
        }
    }
    else{              //k2
        if(k2.food>=3){
            k2.food=(k2.food)-3;
            k2.worker++;
        }
    }
}
void getSoldier(){
    if(Round % 2 != 0){  //k1
        if(k1.gold>=2){
            k1.gold -= 2;
            k1.soldier++;
        }
    }
    else{                //k2
        if(k2.gold>=2){
            k2.gold -= 2;
            k2.soldier++;
        }
    }
}

void drawInformation() {

    //..........................  Round Counter .....................................................
    if(Round % 2 != 0){
        char RoundS[5];
        sprintf(RoundS, "%d", Round);  // Convert int to string
        DrawText("Round: ", 800, 20, 40, DARKBLUE);
        DrawText(RoundS, 950, 20, 40, DARKBLUE);
    }
    else{
        char RoundS[5];
        sprintf(RoundS, "%d", Round);  // Convert int to string
        DrawText("Round: ", 800, 20, 40, PURPLE);
        DrawText(RoundS, 950, 20, 40,     PURPLE);
    }

    //................................................................................................

    //.......................... kingdom 1 information ...............................................
    char s[5];
    sprintf(s, "%d", k1.food);
    DrawText("k1.food: ", 10, 100, 35, DARKBLUE);
    DrawText(s, 210, 100, 40, DARKBLUE);

    sprintf(s, "%d", k1.gold);
    DrawText("k1.gold: ", 10, 150, 35, DARKBLUE);
    DrawText(s, 210, 150, 40, DARKBLUE);

    sprintf(s, "%d", k1.worker);
    DrawText("k1.worker: ", 10, 200, 35, DARKBLUE);
    DrawText(s, 210, 200, 40, DARKBLUE);

    sprintf(s, "%d", k1.soldier);
    DrawText("k1.soldier: ", 10, 250, 35, DARKBLUE);
    DrawText(s, 210, 250, 40, DARKBLUE);

    sprintf(s, "%d", k1.goldProduction);
    DrawText("k1.gold Production: ", 10, 300, 35, DARKBLUE);
    DrawText(s, 390, 300, 40, DARKBLUE);

    sprintf(s, "%d", k1.foodProduction);
    DrawText("k1.food Production: ", 10, 350, 35, DARKBLUE);
    DrawText(s, 400, 350, 40, DARKBLUE);
    //.................................................................................................

    //.......................... kingdom 2 information ...............................................
    //char s[5];
    sprintf(s, "%d", k2.food);
    DrawText("k2.food: ", 10, 500, 35, DARKPURPLE);
    DrawText(s, 210, 500, 40, DARKPURPLE);

    sprintf(s, "%d", k2.gold);
    DrawText("k2.gold: ", 10, 550, 35, DARKPURPLE);
    DrawText(s, 210, 550, 40, DARKPURPLE);

    sprintf(s, "%d", k2.worker);
    DrawText("k2.worker: ", 10, 600, 35, DARKPURPLE);
    DrawText(s, 210, 600, 40, DARKPURPLE);

    sprintf(s, "%d", k2.soldier);
    DrawText("k2.soldier: ", 10, 650, 35, DARKPURPLE);
    DrawText(s, 210, 650, 40, DARKPURPLE);

    sprintf(s, "%d", k2.goldProduction);
    DrawText("k2.gold Production: ", 10, 700, 35, DARKPURPLE);
    DrawText(s, 390, 700, 40, DARKPURPLE);

    sprintf(s, "%d", k2.foodProduction);
    DrawText("k2.food Production: ", 10, 750, 35, DARKPURPLE);
    DrawText(s, 400, 750, 40, DARKPURPLE);
    //.................................................................................................


    //.....................................  Round Guide  ..............................................
    DrawText("key 1  >> buyFood ", 1600, 60, 30, DARKGRAY);
    DrawText("key 2 >> getWorker ", 1600, 90, 30, DARKGRAY);
    DrawText("key 3 >> getSoldier ", 1600, 120, 30, DARKGRAY);
    DrawText("click on the cell you want >> makeRoad", 1300, 30, 30, DARKGRAY);
    DrawText("key 4 >> doNothing ", 1600, 150, 30, DARKGRAY);
    //...................................................................................................

    //....................... Color introduction (difficulty level) .....................................
    Color level1 = (Color){0, 146, 115, 16};
    Color level2 = (Color){0, 146, 115, 32};
    Color level3 = (Color){0, 146, 115, 64};
    Color level4 = (Color){0, 146, 115, 128};
    Color level5 = (Color){0, 146, 115, 255};
    DrawText("Hardest", 1550, 450, 30, DARKGRAY);
    DrawRectangle(1600, 520, cellSize-2, cellSize-2, level5);
    DrawRectangle(1600, 570, cellSize-2, cellSize-2, level4);
    DrawRectangle(1600, 620, cellSize-2, cellSize-2, level3);
    DrawRectangle(1600, 670, cellSize-2, cellSize-2, level2);
    DrawRectangle(1600, 720, cellSize-2, cellSize-2, level1);
    DrawText("Easiest", 1550, 770, 30, DARKGRAY);
    DrawText("Number of\nneeded workers", 1700, 450, 27, DARKGRAY);
    DrawText(" --->  5", 1650, 520, 30, DARKGRAY);
    DrawText(" --->  4", 1650, 570, 30, DARKGRAY);
    DrawText(" --->  3", 1650, 620, 30, DARKGRAY);
    DrawText(" --->  2", 1650, 670, 30, DARKGRAY);
    DrawText(" --->  1", 1650, 720, 30, DARKGRAY);
    //................................................................................................
}