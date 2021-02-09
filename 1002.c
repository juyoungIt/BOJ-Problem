/*
 * Q.1002 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calDist(int* tc);
int eSearch(int* tc);

int main()
{
    int tcNum;
    int** testCase;

    scanf("%d", &tcNum);
    testCase = (int**)malloc(sizeof(int*) * tcNum);
    for(int i=0 ; i<tcNum ; i++) {
        testCase[i] = (int*)malloc(sizeof(int) * 6);
        scanf("%d %d %d %d %d %d", &testCase[i][0], &testCase[i][1], &testCase[i][2],
              &testCase[i][3], &testCase[i][4], &testCase[i][5]);
    }

    for(int i=0 ; i<tcNum ; i++)
        printf("%d\n", eSearch(testCase[i]));

    for(int i=0 ; i<tcNum ; i++)
        free(testCase[i]);
    free(testCase);
    return 0;
}

int calDist(int* tc)
{
    int distX, distY;
    int dist;

    distX = (int)abs(tc[0] - tc[3]); // |x1-x2|
    distY = (int)abs(tc[1] - tc[4]); // |y1-y2|
    dist = (int)pow(distX, 2) + (int)pow(distY, 2);
    return dist;
}

int eSearch(int* tc)
{
    int dist = calDist(tc);
    int len; // the value of r1+r2

    len = tc[2] + tc[5]; // r1+r2
    if(dist == 0) {
        if(tc[2] == tc[5]) // r1 == r2
            return -1;
        else // r1 != r2
            return 0;
    }
    else {
        if(dist == (int)pow(len,2))
            return 1;
        else if(dist < pow(len, 2))
            return 2;
        else
            return 0;
    }
}