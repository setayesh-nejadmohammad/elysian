#ifndef ELYSIAN_WAR_H
#define ELYSIAN_WAR_H
#include <stdbool.h>

void roadClear();
bool war();
void dfs();
void checkRoad();

extern bool mark[17][17];
extern bool validRoad[17][17];

#endif //ELYSIAN_WAR_H
