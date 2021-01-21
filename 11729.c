/*
 * Q.11729 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

#define NUM1 1 // bar1 - source
#define NUM2 2 // bar2 - stopover
#define NUM3 3 // bar3 - destination

// declaration of function
void hanoi(int n, int src, int stp, int dst);

int main()
{
    int blockCount;     // number of blocks
    int moveCount = 0;  // number of moves

    scanf("%d", &blockCount);
    hanoi(blockCount, NUM1, NUM2, NUM3);
    return 0;
}

// definition of function
void hanoi(int n, int src, int stp, int dst)
{
    if(n == 1)
        printf("%d %d\n", src, dst);
    else {
        hanoi(n-1, src, dst, stp);
        printf("%d %d\n", src, dst);
        hanoi(n-1, stp, src, dst);
    }
}