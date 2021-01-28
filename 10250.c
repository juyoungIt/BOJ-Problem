/*
 * Q.10250 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tcNum;       // the number of test case
    int** testCase;  // store each test case
    int* result;     // store each test case processing result
    int floor, rNumber;  // floor, room number
    int h, n;     // store each test case variable

    scanf("%d", &tcNum);
    // memory allocation of test case, result array
    testCase = (int**)malloc(sizeof(int*) * tcNum);
    for(int i=0 ; i<tcNum ; i++)
        testCase[i] = (int*)malloc(sizeof(int*) * 3);
    result = (int*)malloc(sizeof(int) * tcNum);

    for(int i=0 ; i<tcNum ; i++) {
        scanf("%d %d %d", &testCase[i][0], &testCase[i][1], &testCase[i][2]);
        h = testCase[i][0];
        n = testCase[i][2];
        floor = n%h;
        rNumber = n/h+1;
        if(floor == 0) {
            floor = h; // adjust each value - 1
            rNumber--; // adjust each value - 2
        }
        result[i] = floor*100 + rNumber; // calculate room number
    }

    // print processing result of each test case
    for(int i=0 ; i<tcNum ; i++)
        printf("%d\n", result[i]);
    return 0;
}