#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include "runaway.h"
#include <stdbool.h>

#define MAX_SIZE 100
#define OBSTACLE 'x'
#define EMPTY 0

typedef struct{
    int x;
    int y;
}Point;

//int n, m;
char grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
Point parent[MAX_SIZE][MAX_SIZE]; // For tracking the path

// Movement directions (up, down, left, right)
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS search function
bool bfs(Point start, Point end, int n, int m) {
    // Using a queue to store points
    Point queue[MAX_SIZE * MAX_SIZE];
    int front = -1, rear = -1;

    // Enqueue the starting point
    rear++;
    queue[rear] = start;
    visited[start.x][start.y] = true;

    while (front != rear) {
        front++;
        Point current = queue[front];

        // If we reached the destination
        if (current.x == end.x && current.y == end.y) {
            return true;
        }

        // Check all directions
        for (int i = 0; i < 4; i++) {
            int newX = current.x + directions[i][0];
            int newY = current.y + directions[i][1];

            // Check within bounds and avoid obstacles
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                grid[newX][newY] != OBSTACLE && !visited[newX][newY]) {

                visited[newX][newY] = true;
                parent[newX][newY] = current; // Store path
                rear++;
                queue[rear] = (Point){newX, newY}; // Enqueue
            }
        }
    }
    return false; // If we didn't reach the destination
}

// Function to print the path and fill cells except the path
void markPath(Point end, int map[][17]) {
    Point at = end;
    while (at.x != -1) {
        grid[at.x][at.y] = 'r'; // Mark path with 'o'
        //map[at.x][at.y] = 'r';
        at = parent[at.x][at.y];
    }
}

void printGrid(Point start, Point end, int map[][17], int n, int m, int castleNum) {
    grid[start.x][start.y] = 'c';
    grid[end.x][end.y] = 'v';
    printf("Final Grid:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                printf("0 ");
            }
            else {
                printf("%c ", grid[i][j]);
                if(grid[i][j] == 'r') {
                    if(castleNum == 1) map[i][j] = 'r';
                    else if(castleNum == 2) map[i][j] = 'R';
                }
            }
        }
        printf("\n");
    }
    if(castleNum == 1) map[start.x][start.y] = 'c';
    else if(castleNum == 2) map[start.x][start.y] = 'b';
    map[end.x][end.y] = 'v';
}

void road(int map[][17], int n, int m, Point start, Point end, int castleNum) {
    /*printf("Enter the dimensions of the grid (n m): ");
    scanf("%d %d", &n, &m);*/

    // Initialize the grid with zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = EMPTY; // Fill with zero
            visited[i][j] = false; // Set visited status
            parent[i][j] = (Point){-1, -1}; // Set default parent value
        }
    }

    //Copy map[][] in grid[][]
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            if(map[i][j] == 'x' || map[i][j] == 'c' || map[i][j] == 'b'){
                grid[i][j] = OBSTACLE;
            }
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }


    // Get obstacle coordinates
    /*int obstacleCount;
    printf("Number of obstacles: ");
    scanf("%d", &obstacleCount);
    printf("Obstacle coordinates (x y):\n");
    for (int i = 0; i < obstacleCount; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        grid[x - 1][y - 1] = OBSTACLE; // -1 for zero-based index
    }*/
    //grid[7][0] = OBSTACLE;

    /*
    Point start, end;
    printf("Start position (x y): ");
    scanf("%d %d", &start.x, &start.y);
    start.x--; start.y--; // Convert to zero-based index

    printf("End position (x y): ");
    scanf("%d %d", &end.x, &end.y);
    end.x--; end.y--; // Convert to zero-based index
    */

    // Check for path
    if (bfs(start, end, n, m)) {
        markPath(end, map); // Mark the path on the grid
        printGrid(start, end, map, n, m, castleNum);   // Print the final grid
    } else {
        printf("No path exists.\n");
    }

}

