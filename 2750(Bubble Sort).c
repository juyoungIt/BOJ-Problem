/*
 * Q.2750 Solution Source Code (Bubble Sort)
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tcSize;
    int* tc;
    int tmp;

    scanf("%d", &tcSize);
    tc = (int*)malloc(sizeof(int) * tcSize);
    for(int i=0 ; i<tcSize ; i++)
        scanf("%d", &tc[i]);

    for(int i=0 ; i<tcSize ; i++) {
        for(int j=tcSize-1 ; j>i ; j--) {
            if(tc[j] < tc[j-1]) {
                tmp = tc[j];
                tc[j] = tc[j-1];
                tc[j-1] = tmp;
            }
        }
    }

    for(int i=0 ; i<tcSize ; i++)
        printf("%d\n", tc[i]);
    free(tc);
    return 0;
}