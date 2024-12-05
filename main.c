#include <stdio.h>
#include "raylib.h"


const int maxRow = 17;
const int maxCol = 17;
const int cellSize = 50;
const int windowSize = 1050;
int startX = (windowSize - (maxCol*cellSize)) / 2 + 400;
int startY = (windowSize - (maxRow*cellSize)) / 2;


//draw a table.
void drawGrid(int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            DrawRectangle(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, LIGHTGRAY);
            DrawRectangleLines(startX + j*cellSize, startY + i*cellSize, cellSize, cellSize, DARKGRAY);
        }
    }
}

void DrawUser(int x, int y){    //x and y are chosen by user and this function will change the color of that position.
    DrawRectangle(startX + x*cellSize, startY + y*cellSize, cellSize, cellSize, RED);
}
void drawCastle(int x, int y, int n, int m) {
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D castle= LoadTexture("D://git projects//elysian//pics//castle.png");
    DrawTexture(castle, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawVillage(int x, int y, int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D village = LoadTexture("D://git projects//elysian//pics//village.png");
    DrawTexture(village, startX + x * cellSize, startY + y * cellSize, WHITE);
}
void drawBlock(int x, int y, int n, int m){
    int startX = (windowSize - (m*cellSize)) / 2 + 400;
    int startY = (windowSize - (n*cellSize)) / 2;
    Texture2D block = LoadTexture("D://git projects//elysian//pics//block.png");
    DrawTexture(block, startX + x * cellSize, startY + y * cellSize, WHITE);
}







int main(void) {
    //*********************************************************************************************************
    int n, m;
    printf("Enter the dimensions of the game:(it will be a n*m table)\n");
    printf("n = ");
    scanf("%d", &n); //get the table row num
    printf("m = ");
    scanf("%d", &m); //get the table column num

    /*int map[17][17]={0};

    printf("number of castles(1 or 2): ");
    int castleNum, castle1, castle2;
    scanf("%d", &castleNum);                //get the number of castles
    int x1, y1, x2, y2;
    if(castleNum==1){
        printf("castle 1 coordinations(x1, y1):\n");        //get castles coordinates
        printf("x1 = ");
        scanf("%d", &x1);
        printf("y1 = ");
        scanf("%d", &y1);
    }
    else{
        printf("castle 1 coordinations(x1, y1):\n");
        printf("x1 = ");
        scanf("%d", &x1);
        printf("y1 = ");
        scanf("%d", &y1);
        printf("castle 2 coordinations(x2, y2):\n");
        printf("x2 = ");
        scanf("%d", &x2);
        printf("y2 = ");
        scanf("%d", &y2);
    }

    printf("Enter the number of village(max = 25): ");
    int villNum;
    scanf("%d", &villNum);
    for(int i = 0; i<villNum; i++){
        int x, y;
        printf("Enter the coordination of village number %d: ", i+1);
        scanf("%d %d", &x, &y);
        map[x-1][y-1] = 'v';
    }
    int gold[25], food[25];
    for(int i = 0; i<villNum; i++){
        printf("Enter the gold and food for village number %d: ", i+1);
        scanf("%d %d", &gold[i], &food[i]);
    }

    printf("Enter the number of block: ");
    int blockNum;
    scanf("%d", &blockNum);
    for(int i = 0; i<blockNum; i++){
        int x, y;
        printf("Enter the coordanation of block number %d: ", i+1);
        scanf("%d %d", &x, &y);
        map[x-1][y-1] ='x';
    }


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i+1 == x1 && j+1 == y1){
                //printf("c1 ");
                map[i][j] = 'c';
            }
                /*else if(i == x2 && j == y2){
                    printf("c2 ");
                    map[i][j] = 'b';
                }*/ /*
            else if(map[i][j] == 0){
                //printf(" 1 ");
                map[i][j] = 1;
            }
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            printf(" %d ", map[i][j]);
        }
        printf("\n");
    } */
    //*********************************************************************************************************
    InitWindow(0, 0, "main screen");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Texture2D duck= LoadTexture("D://FUM//projects//elysian//duck.png");
    Texture2D table1 = LoadTexture("D://FUM//projects//elysian//duck.png");
    Texture2D village= LoadTexture("pics/village.png");
    Texture2D castle= LoadTexture("pics/castle.png");
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(GRAY);

        //DrawText("Elysian!", 850, 500, 80, BLACK);
        //DrawTexture(duck,100,100,WHITE);

        //ClearBackground(RAYWHITE);
        drawGrid(n,m);





        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
