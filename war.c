//
// Created by setayesh on 1/5/2025.
//

#include "war.h"
#include "draw.h"
#include <stdbool.h>

bool mark[17][17] = {false};
bool validRoad[17][17] = {false};

void dfs(int x, int y){
    mark[x][y] = true;
    if(x - 1 >= 0 && map[x-1][y] == 2 && !mark[x-1][y]){
        dfs(x-1, y);
    }
    if(y - 1 >= 0 && map[x][y-1] == 2 && !mark[x][y-1]){
        dfs(x, y-1);
    }
    if(x + 1 < n && map[x+1][y] == 2 && !mark[x+1][y]){
        dfs(x+1, y);
    }
    if(y + 1 < m && map[x][y+1] == 2 && !mark[x][y+1]){
        dfs(x, y+1);
    }
}


void roadClear(int x, int y, int state){ // state shows that which Kingdom won the war
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 17; j++){
            mark[i][j] = false;
            validRoad[i][j] = false;
        }
    }

    dfs(x, y);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mark[i][j] && map[i][j] != 0){
                map[i][j] = -1;
            }
        }
    }
}