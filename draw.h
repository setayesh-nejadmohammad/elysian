// draw.h
#ifndef draw_H
#define draw_H
#include <stdbool.h>
#include "info.h"

// Function declarations (prototypes)
void drawGrid();
void drawCastle1();
void drawCastle2();
void drawVillage();
void drawBlock();
void Map();
void generate_random();
bool Way();
void drawInformation();
// ... other declarations

// Struct declarations





// Variable declarations (if global)
extern int windowSize;  // Declare as extern to indicate it's defined elsewhere
extern int cellSize;
extern int n;
extern int m;
extern int villNum;
extern int castleNum;
extern int startX, startY;
extern int maxRow, maxCol;
extern int map[17][17];
extern kingdom k1, k2;
extern village v[25];
extern int UntakenVills;

#endif // DRAW_H