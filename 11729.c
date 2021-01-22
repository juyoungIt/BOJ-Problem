/*
 * Q.11729 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

#define NUM1 1 // bar1 - source
#define NUM2 2 // bar2 - stopover
#define NUM3 3 // bar3 - destination

// declaration of function
void countHanoi(int* mc, int n); // count number of moves
void printHanoi(int n, int src, int stp, int dst); // print each moves

int main()
{
    int blockCount;     // number of blocks
    int** solution;     // save hanoi tower solution
    int moveCount = 0;  // number of moves

    scanf("%d", &blockCount);
    countHanoi(&moveCount, blockCount);
    printf("%d\n", moveCount);
    printHanoi(blockCount, NUM1, NUM2, NUM3);
    return 0;
}

// definition of function
void countHanoi(int* mc, int n)
{
    if(n == 1)
        (*mc)++;
    else {
        countHanoi(mc, n-1);
        (*mc)++;
        countHanoi(mc, n-1);
    }
}

void printHanoi(int n, int src, int stp, int dst)
{
    if(n == 1)
        printf("%d %d\n", src, dst);
    else {
        printHanoi(n-1, src, dst, stp);
        printf("%d %d\n", src, dst);
        printHanoi(n-1, stp, src, dst);
    }
}