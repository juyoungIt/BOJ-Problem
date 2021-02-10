/*
 * Q.1002 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calDist(int* tc);
int eSearch(double dist, int r1, int r2);

int main()
{
    int tcNum; // the number of test case
    int** tc;  // store all test case

    scanf("%d", &tcNum);
    tc = (int**)malloc(sizeof(int*) * tcNum);
    for(int i=0 ; i<tcNum ; i++) {
        tc[i] = (int*)malloc(sizeof(int) * 6);
        scanf("%d %d %d %d %d %d", &tc[i][0], &tc[i][1], &tc[i][2], &tc[i][3], &tc[i][4], &tc[i][5]);
    }

    for(int i=0 ; i<tcNum ; i++)
        printf("%d\n", eSearch(calDist(tc[i]), tc[i][2], tc[i][5]));

    for(int i=0 ; i<tcNum ; i++)
        free(tc[i]);
    free(tc);
    return 0;
}

double calDist(int* tc)
{
    double dist;
    dist = sqrt(pow(abs(tc[0]-tc[3]), 2) + pow(abs(tc[1]-tc[4]), 2));
    return dist;
}

int eSearch(double dist, int r1, int r2)
{
    int bigR, smallR;

    bigR = (r1>r2) ? r1 : r2;
    smallR = (r1>r2) ? r2 : r1;
    if(dist > r1+r2)
        return 0;
    else if(dist == r1+r2)
        return 1;
    else {
        if(dist!=0 && dist+smallR == bigR)
            return 1;
        else if(dist+smallR < bigR) {
            if(dist==0 && r1!=r2)
                return 0;
            return 0;
        }
        else {
            if(dist==0 && r1==r2)
                return -1;
            else
                return 2;
        }
    }
}