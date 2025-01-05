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

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    int x,y;
    int food;
    int gold;
    int soldier;
    int worker;
    int goldProduction;
    int foodProduction;
    Point road[100];
    int roadCount;
    int vills[25];
    int villnum;
}kingdom;


typedef struct{
    int x,y;
    bool free;   // This will check if a village is free(free = true) or taken(free = false) by a kingdom
    int foodRate;
    int goldRate;
}village;



#endif //ELYSIAN_INFO_H