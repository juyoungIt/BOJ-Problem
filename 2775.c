/*
 * Q.2775 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

// function declaration
int howMany(int k, int n); // the number of people ('k' floor, 'n' number)

int main()
{
    int tcNum;       // the number of test case
    int** testCase;  // store test case
    int* result;     // store test case processing result
    int k, n;        // k = floor, n = room number

    scanf("%d", &tcNum);
    testCase = (int**)malloc(sizeof(int*) * tcNum);
    for(int i=0 ; i<tcNum ; i++)
        testCase[i] = (int*)malloc(sizeof(int) * 2);
    result = (int*)malloc(sizeof(int) * tcNum);

    for(int i=0 ; i<tcNum ; i++) {
        scanf("%d", &testCase[i][0]);
        scanf("%d", &testCase[i][1]);
        result[i] = howMany(testCase[i][0], testCase[i][1]);
    }

    for(int i=0 ; i<tcNum ; i++)
        printf("%d\n", result[i]);

    for(int i=0 ; i<tcNum ; i++)
        free(testCase[i]);
    free(testCase);
    free(result);
    return 0;
}

// function definition
int howMany(int k, int n)
{
    if(k == 0)
        return n;
    else if(n == 1)
        return 1;
    else
        return howMany(k, n-1) + howMany(k-1, n);
}