/*
 * Q.2447 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

// declaration of function
void drawPattern(char** g, int x, int y, int n); // draw star in (x, y) location
void drawSpace(char** g, int x, int y, int n); // draw space in (x, y) location

int main()
{
    int n;    // pattern size
    char** grid; // grid for pattern drawing

    scanf("%d", &n); // input pattern size
    grid = (char**)malloc(sizeof(char*)*n);
    for(int i=0 ; i<n ; i++)
        grid[i] = (char*)malloc(sizeof(char)*n);

    drawPattern(grid, 0, 0, n);

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    for(int i=0 ; i<n ; i++)
        free(grid[i]);
    free(grid);

    return 0;
}

// definition of function
void drawPattern(char** g, int x, int y, int n)
{
    if(n == 3) {
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                if(i == 1 && j == 1)
                    drawSpace(g, x+j, y+i, 1);
                else
                    g[y+i][x+j] = '*';
            }
        }
    }
    else {
        for(int i=0 ; i<3 ; i++) {
            for(int j=0 ; j<3 ; j++) {
                if(i == 1 && j == 1)
                    drawSpace(g, x+n/3, y+n/3, n/3);
                else
                    drawPattern(g, x+n/3*j, y+n/3*i, n/3);
            }
        }
    }
}

// draw NxN size space rectangle from (x,y)
void drawSpace(char** g, int x, int y, int n)
{
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            g[y+i][x+j] = ' ';
        }
    }
}