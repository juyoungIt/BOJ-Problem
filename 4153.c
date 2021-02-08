/*
 * Q.4153 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMax(int* tc);

int main()
{
    int tcNum = 0;
    int** testCase = NULL;
    int maxLen;
    int len1, len2;
    int count;

    while(1) {
        testCase = (int**)realloc(testCase, sizeof(int*) * (tcNum+1));
        testCase[tcNum] = (int*)malloc(sizeof(int) * 3);
        scanf("%d %d %d", &testCase[tcNum][0], &testCase[tcNum][1], &testCase[tcNum][2]);
        if(testCase[tcNum][0] == 0 && testCase[tcNum][1] == 0 && testCase[tcNum][2] == 0)
            break;
        tcNum++;
    }
    for(int i=0 ; i<tcNum ; i++) {
        maxLen = findMax(testCase[i]);
        count = 0;
        for(int j=0 ; j<3 ; j++) {
            if(count == 0 && testCase[i][j] != maxLen)
                len1 = testCase[i][j];
            else if(testCase[i][j] != maxLen)
                len2 = testCase[i][j];
            count++;
        }
        if(pow(maxLen, 2) == (pow(len1, 2) + pow(len2, 2)))
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}

int findMax(int* tc)
{
    int max = tc[0];
    for(int i=0 ; i<3 ; i++) {
        if(max < tc[i])
            max = tc[i];
    }
    return max;
}