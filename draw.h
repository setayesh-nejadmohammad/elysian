// draw.h
#ifndef draw_H
#define draw_H

typedef struct{
    int x;
    int y;
}Point;

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
extern int villNum;
extern  Point villCordination[25];
#endif // DRAW_H

