/*
 * Q.2447 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

// declaration of function
void drawStar(int n); // draw 'N' pattern star

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
void drawStar(int n)
{
    // base case
    // general case
}