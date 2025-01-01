#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "info.h"


void update(){
    k1.gold += k1.goldProduction;
    k1.food += k1.foodProduction;
}

void buyFood(){
    if(k1.gold>=1){
        k1.food++;
        k1.gold--;
    }
}
void getWorker(){
    if(k1.food>=3){
        k1.food=(k1.food)-3;
        k1.worker++;
    }
}
void getSoldier(){
    if(k1.gold>=2){
        k1.gold -= 2;
        k1.soldier++;
    }
}
