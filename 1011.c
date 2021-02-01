/*
 * Q.1011 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tcNum;       // the number of test case
    int** testCase;  // store all test case

    scanf("%d", &tcNum);
    // memory allocation
    testCase = (int**)malloc(sizeof(int*) * tcNum);
    for(int i=0 ; i<tcNum ; i++)
        testCase[i] = (int*)malloc(sizeof(int) * 2);

    /*
     * Solution Algorithm here...
     */

    // free memory space
    for(int i=0 ; i<tcNum ; i++)
        free(testCase[i]);
    free(testCase);
    return 0;
}