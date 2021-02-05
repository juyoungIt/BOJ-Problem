/*
 * Q.1011 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

// function declaration
int bestSol(int x, int y); // find best solution value of test case

int main()
{
    int tcNum;       // the number of test case
    int** testCase;  // store all test case
    int* result;     // store solution value of each test case

    scanf("%d", &tcNum);
    testCase = (int**)malloc(sizeof(int*) * tcNum);
    result = (int*)malloc(sizeof(int) * tcNum);
    for(int i=0 ; i<tcNum ; i++)
        testCase[i] = (int*)malloc(sizeof(int) * 2);

    for(int i=0 ; i<tcNum ; i++) {
        scanf("%d %d", &testCase[i][0], &testCase[i][1]);
        result[i] = bestSol(testCase[i][0], testCase[i][1]);
    }

    for(int i=0 ; i<tcNum ; i++)
        printf("%d\n", result[i]);

    // free memory space
    for(int i=0 ; i<tcNum ; i++)
        free(testCase[i]);
    free(testCase);
    return 0;
}

// function definition
int bestSol(int x, int y) {
    int count; // execute count
    int dist = y-x; // distance
    int n; // the loop variable

    n = 1; // initialize loop variable
    while(1) {
        if(n*(n+1) >= dist) {
            if(n*(n+1)-n < dist)
                count = n*2;
            else
                count = n*2-1;
            break;
        }
        n++;
    }
    return count;
}