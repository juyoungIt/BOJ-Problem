/*
 * Q.1003 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

void fibo(int n, int* z, int* o);

int main()
{
    int tcSize;
    int* tc;
    int zero=0, one=0;

    scanf("%d", &tcSize);
    tc = (int*)malloc(sizeof(int) * tcSize);
    for(int i=0 ; i<tcSize ; i++)
        scanf("%d", &tc[i]);

    for(int i=0 ; i<tcSize ; i++) {
        fibo(tc[i], &zero, &one);
        printf("%d %d\n", zero, one);
        zero = 0;
        one = 0;
    }
    free(tc);
    return 0;
}

void fibo(int n, int* z, int* o)
{
    if(n == 0)
        *z += 1;
    else if(n == 1)
        *o += 1;
    else {
        fibo(n-1, z, o);
        fibo(n-2, z, o);
    }
}