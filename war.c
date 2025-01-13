//
// Created by setayesh on 1/5/2025.
//

#include "war.h"
#include "draw.h"
#include <stdbool.h>
#include <stdio.h>

bool mark[17][17] = {false};
bool validRoad[17][17] = {false};

void dfs(int x, int y, int state){
    mark[x][y] = true;
    char road; // road will be 'R' or 'r'
    if(state == 1) road = 'R'; // state tells which kingdom win ... if k1 win we should remove 'R'(k2 roads) if k2 wins we remove 'r'(k1 roads)
    else if(state == 2) road = 'r';
    if(x - 1 >= 0 && map1[x-1][y] == road && !mark[x-1][y]){
        dfs(x-1, y, state);
    }
    if(y - 1 >= 0 && map1[x][y-1] == road && !mark[x][y-1]){
        dfs(x, y-1, state);
    }
    if(x + 1 < n && map1[x+1][y] == road && !mark[x+1][y]){
        dfs(x+1, y, state);
    }
    if(y + 1 < m && map1[x][y+1] == road && !mark[x][y+1]){
        dfs(x, y+1, state);
    }
}

void checkRoad(int x, int y, int state){ // get the coordination of the kingdom
    validRoad[x][y] = true;
    char road; // road will be 'R' or 'r'
    char vill; // vill will be 'V' or 'W'
    if(state == 1){
        road = 'R';
        vill = 'W';
    }
    else if(state == 2){
        road = 'r';
        vill = 'V';
    }

    if(x - 1 >= 0 && (map1[x-1][y] == road || map1[x-1][y] == vill) && !validRoad[x-1][y]){
        checkRoad(x-1, y, state);
    }
    if(y - 1 >= 0 && (map1[x][y-1] == road || map1[x][y-1] == vill) && !validRoad[x][y-1]){
        checkRoad(x, y-1, state);
    }
    if(x + 1 < n && (map1[x+1][y] == road || map1[x+1][y] == vill) && !validRoad[x+1][y]){
        checkRoad(x+1, y, state);
    }

    if(y + 1 < m && (map1[x][y+1] == road || map1[x][y+1] == vill) && !validRoad[x][y+1]){
        checkRoad(x, y+1, state);
    }
}

void roadClear(int x, int y, int state){ // state shows that which Kingdom won the war
    for(int i = 0; i < 17; i++){
        for(int j = 0; j < 17; j++){
            mark[i][j] = false;
            validRoad[i][j] = false;
        }
    }

    dfs(x, y, state);

    // ................... remove the losers roads and put the previous random num instead of it ..........
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mark[i][j] && map1[i][j] != 'c' && map1[i][j] != 'b' && map1[i][j] != 'v' && map1[i][j] != 'V' && map1[i][j] != 'W' && map1[i][j] != 'x'){
                map2[i][j] = map[i][j];
                map1[i][j] = map[i][j];
            }
        }
    }


    //This will remove every road that is not connected to the kingdom.......................
    if(state == 1){
        checkRoad(k2.x, k2.y, 1);
        validRoad[k2.x][k2.y] = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!validRoad[i][j] && map1[i][j] != 'c' && map1[i][j] != 'b' && map1[i][j] != 'v'
                && map1[i][j] != 'V' && map1[i][j] != 'W' && map1[i][j] != 'x' && map1[i][j] != 'r'){
                    map2[i][j] = map[i][j];
                    map1[i][j] = map[i][j];
                }
            }
        }
    }
    else if(state == 2){
        checkRoad(k1.x, k1.y, 2);
        validRoad[k1.x][k1.y] = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!validRoad[i][j] && map2[i][j] != 'c' && map2[i][j] != 'b' && map2[i][j] != 'v'
                   && map2[i][j] != 'V' && map2[i][j] != 'W' && map2[i][j] != 'x' && map2[i][j] != 'R'){
                    map2[i][j] = map[i][j];
                    map1[i][j] = map[i][j];
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(map1[i][j] == 'W'){
                if(map1[i][j-1] != 'R' && map1[i][j+1] != 'R' && map1[i-1][j] != 'R' && map1[i+1][j] != 'R'){
                    for(int t=0 ; t<villNum ; t++){
                        if(i == v[k2.vills[t]].x && j == v[k2.vills[t]].y){
                            v[k2.vills[t]].free = true ;
                            k2.foodProduction -= v[k2.vills[t]].foodRate;
                            k2.goldProduction -= v[k2.vills[t]].goldRate;
                            k2.vills[t] = -1;
                            UntakenVills += 1;
                            break;
                        }
                    }
                    map1[i][j] = 'v';
                    map2[i][j] = 'v';
                }
            }
            else if(map1[i][j] == 'V'){
                if(map1[i][j-1] != 'r' && map1[i][j+1] != 'r' && map1[i-1][j] != 'r' && map1[i+1][j] != 'r'){
                    for(int t=0 ; t<villNum ; t++){
                        if(i == v[k1.vills[t]].x && j == v[k1.vills[t]].y){
                            v[k1.vills[t]].free = true ;
                            k1.foodProduction -= v[k1.vills[t]].foodRate;
                            k1.goldProduction -= v[k1.vills[t]].goldRate;
                            k1.vills[t] = -1;
                            UntakenVills += 1;
                            break;
                        }
                    }
                    map1[i][j] = 'v';
                    map2[i][j] = 'v';
                }
            }
        }
    }
}


bool war(int x,int y) {
    bool IsStillWar;
    bool IsReturnTrue = false;
    int state = -1;
    for(int i = 0; i < 3; i++){
        if (k1.soldier > k2.soldier) {
            state = 1;
            //k1.soldier = k1.soldier - k2.soldier;
            //k2.soldier = 0;
        } else if (k2.soldier > k1.soldier) {
            state = 2;
            //k2.soldier = k2.soldier - k1.soldier;
            //k1.soldier = 0;
        } else if (k1.soldier == k2.soldier){
            state = 0;
            //k1.soldier = 0;
            //k2.soldier = 0;
        }
        IsStillWar = false;
        if (Round % 2 != 0) { //k1
            if (map1[x - 1][y] == 'R') {
                if (state == 1) {
                    roadClear(x - 1,y,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x - 1,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x + 1][y] == 'R') {
                if (state == 1) {
                    roadClear(x + 1,y,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x + 1,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y - 1] == 'R') {
                if (state == 1) {
                    roadClear(x,y-1,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x,y-1,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y + 1] == 'R') {
                if (state == 1) {
                    roadClear(x,y+1,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x,y+1,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            if (map1[x-1][y] == 'W'){
                if (state == 1) {
                    roadClear(x-1,y,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x-1,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x+1][y] == 'W'){
                if (state == 1) {
                    roadClear(x+1,y,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x+1,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y-1] == 'W'){
                if (state == 1) {
                    roadClear(x,y-1,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x,y-1,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y+1] == 'W'){
                if (state == 1) {
                    roadClear(x,y+1,state);
                } else if (state == 2) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,2);
                    roadClear(x,y+1,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            if (map1[x-1][y] == 'b'){
                if(state == 1){
                    UntakenVills = -1;
                    WhoWin = 1; //k1 is the games final winner
                } else if (state == 2) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x-1,y,1);
                    roadClear(x,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x+1][y] == 'b'){
                if(state == 1){
                    UntakenVills = -1;
                    WhoWin = 1; //k1 is the games final winner
                } else if (state == 2) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x+1,y,1);
                    roadClear(x,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y-1] == 'b'){
                if(state == 1){
                    UntakenVills = -1;
                    WhoWin = 1; //k1 is the games final winner
                } else if (state == 2) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x,y-1,1);
                    roadClear(x,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map1[x][y+1] == 'b'){
                if(state == 1){
                    UntakenVills = -1;
                    WhoWin = 1; //k1 is the games final winner
                } else if (state == 2) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x,y+1,1);
                    roadClear(x,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            //return false;
        }
        else if(Round % 2 == 0){ //k2
            if (map2[x - 1][y] == 'r') {
                if (state == 2) {
                    roadClear(x - 1,y,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x - 1,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x + 1][y] == 'r') {
                if (state == 2) {
                    roadClear(x + 1,y,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x + 1,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y - 1] == 'r') {
                if (state == 2) {
                    roadClear(x,y-1,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x,y-1,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y + 1] == 'r') {
                if (state == 2) {
                    roadClear(x,y+1,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x,y+1,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            if (map2[x-1][y] == 'V'){
                if (state == 2) {
                    roadClear(x-1,y,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x-1,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x+1][y] == 'V'){
                if (state == 2) {
                    roadClear(x+1,y,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x+1,y,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y-1] == 'V'){
                if (state == 2) {
                    roadClear(x,y-1,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x,y-1,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y+1] == 'V'){
                if (state == 2) {
                    roadClear(x,y+1,state);
                } else if (state == 1) {
                    roadClear(x,y,state);
                } else if (state == 0) {
                    roadClear(x,y,1);
                    roadClear(x,y+1,2);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            if (map2[x-1][y] == 'c'){
                if(state == 2){
                    UntakenVills = -1;
                    WhoWin = 2; //k2 is the games final winner
                } else if (state == 1) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x-1,y,2);
                    roadClear(x,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x+1][y] == 'c'){
                if(state == 2){
                    UntakenVills = -1;
                    WhoWin = 2; //k2 is the games final winner
                } else if (state == 1) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x+1,y,2);
                    roadClear(x,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y-1] == 'c'){
                if(state == 2){
                    UntakenVills = -1;
                    WhoWin = 2; //k2 is the games final winner
                } else if (state == 1) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x,y-1,2);
                    roadClear(x,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            else if (map2[x][y+1] == 'c'){
                if(state == 2){
                    UntakenVills = -1;
                    WhoWin = 2; //k2 is the games final winner
                } else if (state == 1) {
                    roadClear(x,y,state);
                }else if (state == 0) {
                    roadClear(x,y+1,2);
                    roadClear(x,y,1);
                }
                IsStillWar = true;
                IsReturnTrue = true;
                continue;
                //return true;
            }
            //return false;
        }

    }


    if(IsReturnTrue){
        if (k1.soldier > k2.soldier) {
            state = 1;
            k1.soldier = k1.soldier - k2.soldier;
            k2.soldier = 0;
        } else if (k2.soldier > k1.soldier) {
            state = 2;
            k2.soldier = k2.soldier - k1.soldier;
            k1.soldier = 0;
        } else if (k1.soldier == k2.soldier){
            state = 0;
            k1.soldier = 0;
            k2.soldier = 0;
        }
        return true;
    }
    return false;
}