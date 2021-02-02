/*
 * Q.1978 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tcNum;          // the number of test case
    int* testCase;      // store test case
    int primeCount = 0; // the number of prime number
    int j; // the loop variable

    scanf("%d", &tcNum);
    testCase = (int*)malloc(sizeof(int) * tcNum);
    for(int i=0 ; i<tcNum ; i++)
        scanf("%d", &testCase[i]);

    // access each test case
    for(int i=0 ; i<tcNum ; i++) {
        for(j=1 ; j<=testCase[i] ; j++) {
            if(testCase[i] % j == 0 && (j != 1 && j != testCase[i]))
                break;
        }
        if(testCase[i] != 1 && j == testCase[i]+1)
            primeCount++;
    }
    printf("%d\n", primeCount);
    free(testCase);
    return 0;
}