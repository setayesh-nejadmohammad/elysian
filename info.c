#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "info.h"


void update(kingdom k1){
    k1.gold ++;
}

void buyFood(kingdom k){
    if(k1.gold>=1){
        k1.food++;
        k1.gold--;
    }
}
void getWorker(kingdom k){
    if(k1.food>=3){
        k1.food=(k1.food)-3;
        k1.worker++;
    }
}
void getSoldier(kingdom k){
    if(k1.gold>=2){
        k1.gold=(k1.gold)-2;
        k1.soldier++;
    }
}
bool round(kingdom k) {
    update(k1);
    if (IsKeyPressed(KEY_ONE)) {
        if(k1.gold>=1) {
            return true;
        }
        else {
            return false;
        }
    }
    // draw something to say you cant do this round.
    if(IsKeyPressed(KEY_TWO)){
        if(k1.food>=3){
            getWorker(k1);
            return true;
        }
        else {
            return false;
        }
    }
    if(IsKeyPressed(KEY_THREE)){
        if(k1.gold>=2){
            getSoldier(k1);
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