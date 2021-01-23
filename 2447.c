/*
 * Q.2447 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

// declaration of function
void drawStar(int x, int y, int n); // draw star in (x, y) location
void drawSpace(int x, int y, int n); // draw space in (x, y) location

int main()
{
    int n;    // pattern size
    char** grid; // grid for pattern drawing

    scanf("%d", &n); // input pattern size
    grid = (char**)malloc(sizeof(char*)*n);
    for(int i=0 ; i<n ; i++)
        grid[i] = (char*)malloc(sizeof(char)*n);

    for(int i=0 ; i<n ; i++)
        free(grid[i]);
    free(grid);

    return 0;
}

// definition of function
void drawStar(int x, int y, int n)
{
    // base case
    // general case
}

void drawSpace(int x, int y, int n)
{
    // base case
    // general case
}