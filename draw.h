// draw.h
#ifndef draw_H
#define draw_H

// Function declarations (prototypes)
void drawGrid();
void drawCastle1();
void drawCastle2();
void drawVillage();
void drawBlock();
void Map();
void generate_random();
void way();
// ... other declarations

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

#endif // DRAW_H

