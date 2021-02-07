/*
 * Q.3009 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int findY(int coordinate[][2]);

int main()
{
    int coordinate[3][2]; // store three coordinates of rectangle
    int x, y; // the last coordinate (x, y)

    for(int i=0 ; i<3 ; i++)
        scanf("%d %d", &coordinate[i][0], &coordinate[i][1]);

    y = findY(coordinate);
    for(int i=0 ; i<3 ; i++) {
        if(coordinate[i][1] == y)
            x = coordinate[i][0];
    }
    for(int i=0 ; i<3 ; i++) {
        if(x != coordinate[i][0]) {
            x = coordinate[i][0];
            break;
        }
    }

    printf("%d %d\n", x, y);
    return 0;
}

// find unique Y coordinate
int findY(int coordinate[][2])
{
    if(coordinate[0][1] == coordinate[1][1])
        return coordinate[2][1];
    else {
        if(coordinate[1][1] == coordinate[2][1])
            return coordinate[0][1];
        else
            return coordinate[1][1];
    }
}