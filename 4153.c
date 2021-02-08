/*
 * Q.4153 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMaxIdx(int* tc);

int main()
{
    int tcNum = 0;
    int** testCase = NULL;
    int maxLen, maxIdx;
    int len1, len2;
    int count;
    int num1, num2, num3;

    while(1) {
        testCase = (int**)realloc(testCase, sizeof(int*) * (tcNum+1));
        testCase[tcNum] = (int*)malloc(sizeof(int) * 3);
        scanf("%d %d %d", &testCase[tcNum][0], &testCase[tcNum][1], &testCase[tcNum][2]);
        if(testCase[tcNum][0] == 0 && testCase[tcNum][1] == 0 && testCase[tcNum][2] == 0)
            break;
        tcNum++;
    }
    for(int i=0 ; i<tcNum ; i++) {
        maxIdx = findMaxIdx(testCase[i]);
        maxLen = testCase[i][maxIdx];
        count = 0;
        for(int j=0 ; j<3 ; j++) {
            if(j != maxIdx) {
                if(count == 0)
                    len1 =  testCase[i][j];
                else
                    len2 = testCase[i][j];
                count++;
            }
        }
        num1 = (int)pow(maxLen, 2);
        num2 = (int)pow(len1, 2);
        num3 = (int)pow(len2, 2);
        if(num1 == num2 + num3)
            printf("right\n");
        else
            printf("wrong\n");
    }
    for(int i=0 ; i<tcNum ; i++)
        free(testCase[i]);
    free(testCase);

    return 0;
}

int findMaxIdx(int* tc)
{
    int max = tc[0];
    int maxIdx;
    for(int i=0 ; i<3 ; i++) {
        if(max < tc[i]) {
            max = tc[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}