//
// Created by melina daee on 23/12/2024.
//

#ifndef ELYSIAN_INFO_H
#define ELYSIAN_INFO_H
#include <stdbool.h>


void way();
void buyFood();
void getWorker();
void getSoldier();
void update();
bool round();




typedef struct{
    int x,y;
    int food;
    int gold;
    int soldier;
    int worker;
}kingdom;


typedef struct{
    int x,y;
    bool free;
    bool taken;
}village;



#endif //ELYSIAN_INFO_H
