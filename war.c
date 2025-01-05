//
// Created by melina daee on 05/01/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "draw.h"
#include "info.h"
#include <string.h>
#include "stdbool.h"

bool war(int x,int y) {
    int state = -1;
    if (Round % 2 != 0) { //k1
        if (k1.soldier > k2.soldier) {
            state = 1;
        } else if (k2.soldier > k1.soldier) {
            state = 2;
        } else if (k1.soldier == k2.soldier) {
            state = 0;
        }
        if (map1[x - 1][y] == 'R') {
            if (state == 1) {
                roadClear(map1[x - 1][y]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x - 1][y]);
            }
            return true;
        }
        else if (map1[x + 1][y] == 'R') {
            if (state == 1) {
                roadClear(map1[x + 1][y]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x + 1][y]);
            }
            return true;
        }
        else if (map1[x][y - 1] == 'R') {
            if (state == 1) {
                roadClear(map1[x][y-1]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x][y-1]);
            }
            return true;
        }
        else if (map1[x][y + 1] == 'R') {
            if (state == 1) {
                roadClear(map1[x][y+1]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x][y+1]);
            }
            return true;
        }
        if (map1[x-1][y] == 'W'){
            if (state == 1) {
                roadClear(map1[x-1][y]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x-1][y]);
            }
            return true;
        }
        else if (map1[x+1][y] == 'W'){
            if (state == 1) {
                roadClear(map1[x+1][y]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x+1][y]);
            }
            return true;
        }
        else if (map1[x][y-1] == 'W'){
            if (state == 1) {
                roadClear(map1[x][y-1]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x][y-1]);
            }
            return true;
        }
        else if (map1[x][y+1] == 'W'){
            if (state == 1) {
                roadClear(map1[x][y+1]);
            } else if (state == 2) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map1[x][y]);
                roadClear(map1[x][y+1]);
            }
            return true;
        }
        if (map1[x-1][y] == 'b'){
            if(state == 1){
                UntakenVills = -1;
            } else if (state == 2) {
                roadClear(map1[x][y]);
            }else if (state == 0) {
                roadClear(map1[x-1][y]);
                roadClear(map1[x][y]);
            }
            return true;
        }
        else if (map1[x+1][y] == 'b'){
            if(state == 1){
                UntakenVills = -1;
            } else if (state == 2) {
                roadClear(map1[x][y]);
            }else if (state == 0) {
                roadClear(map1[x+1][y]);
                roadClear(map1[x][y]);
            }
            return true;
        }
        else if (map1[x][y-1] == 'b'){
            if(state == 1){
                UntakenVills = -1;
            } else if (state == 2) {
                roadClear(map1[x][y]);
            }else if (state == 0) {
                roadClear(map1[x][y-1]);
                roadClear(map1[x][y]);
            }
            return true;
        }
        else if (map1[x][y+1] == 'b'){
            if(state == 1){
                UntakenVills = -1;
            } else if (state == 2) {
                roadClear(map1[x][y]);
            }else if (state == 0) {
                roadClear(map1[x][y+1]);
                roadClear(map1[x][y]);
            }
            return true;
        }
            return false;
    }
    else if(Round % 2 == 0){ //k2
        if (k1.soldier > k2.soldier) {
            state = 1;
        } else if (k2.soldier > k1.soldier) {
            state = 2;
        } else if (k1.soldier == k2.soldier) {
            state = 0;
        }
        if (map2[x - 1][y] == 'r') {
            if (state == 2) {
                roadClear(map2[x - 1][y]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x - 1][y]);
            }
            return true;
        }
        else if (map2[x + 1][y] == 'r') {
            if (state == 2) {
                roadClear(map2[x + 1][y]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x + 1][y]);
            }
            return true;
        }
        else if (map2[x][y - 1] == 'r') {
            if (state == 2) {
                roadClear(map2[x][y-1]);
            } else if (state == 2) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x][y-1]);
            }
            return true;
        }
        else if (map2[x][y + 1] == 'r') {
            if (state == 2) {
                roadClear(map2[x][y+1]);
            } else if (state == 1) {
                roadClear(map1[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x][y+1]);
            }
            return true;
        }
        if (map2[x-1][y] == 'V'){
            if (state == 2) {
                roadClear(map2[x-1][y]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x-1][y]);
            }
            return true;
        }
        else if (map2[x+1][y] == 'V'){
            if (state == 2) {
                roadClear(map2[x+1][y]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x+1][y]);
            }
            return true;
        }
        else if (map2[x][y-1] == 'V'){
            if (state == 2) {
                roadClear(map2[x][y-1]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x][y-1]);
            }
            return true;
        }
        else if (map2[x][y+1] == 'V'){
            if (state == 2) {
                roadClear(map2[x][y+1]);
            } else if (state == 1) {
                roadClear(map2[x][y]);
            } else if (state == 0) {
                roadClear(map2[x][y]);
                roadClear(map2[x][y+1]);
            }
            return true;
        }
        if (map2[x-1][y] == 'c'){
            if(state == 2){
                UntakenVills = -1;
            } else if (state == 1) {
                roadClear(map[x][y]);
            }else if (state == 0) {
                roadClear(map2[x-1][y]);
                roadClear(map2[x][y]);
            }
            return true;
        }
        else if (map2[x+1][y] == 'c'){
            if(state == 2){
                UntakenVills = -1;
            } else if (state == 1) {
                roadClear(map2[x][y]);
            }else if (state == 0) {
                roadClear(map2[x+1][y]);
                roadClear(map2[x][y]);
            }
            return true;
        }
        else if (map2[x][y-1] == 'c'){
            if(state == 2){
                UntakenVills = -1;
            } else if (state == 1) {
                roadClear(map2[x][y]);
            }else if (state == 0) {
                roadClear(map2[x][y-1]);
                roadClear(map2[x][y]);
            }
            return true;
        }
        else if (map2[x][y+1] == 'c'){
            if(state == 2){
                UntakenVills = -1;
            } else if (state == 1) {
                roadClear(map2[x][y]);
            }else if (state == 0) {
                roadClear(map2[x][y+1]);
                roadClear(map2[x][y]);
            }
            return true;
        }
        return false;
    }
}
