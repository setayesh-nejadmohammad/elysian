#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "info.h"


void update(){
    k1.gold += k1.goldProduction;
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
        k1.gold=(k1.gold)-2;
        k1.soldier++;
    }
}
bool round(kingdom k) {
    update(k);
    if (IsKeyPressed(KEY_ONE)) {
        if(k.gold>=1) {
            return true;
        }
        else {
            return false;
        }
    }
    // draw something to say you cant do this round.
    if(IsKeyPressed(KEY_TWO)){
        if(k.food>=3){
            getWorker(k);
            return true;
        }
        else {
            return false;
        }
    }
    if(IsKeyPressed(KEY_THREE)){
        if(k.gold>=2){
            getSoldier(k);
            return true;
        }
        else {
            return false;
        }
    }
    if(IsKeyPressed(KEY_FOUR)){
        way();
        return true;
    }
    if(IsKeyPressed(KEY_FIVE)){
        return false;
    }
}