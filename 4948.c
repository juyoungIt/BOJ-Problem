/*
 * Q.4948 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min;
    int size = 0; // the number of test case
    int* tc = NULL;
    int prime = 0; // the number of prime number
    int* num;

    // enter test case
    while(1) {
        scanf("%d", &min);
        if(min == 0) break;
        size++;
        tc = (int*)realloc(tc, sizeof(int) * size);
        tc[size-1] = min;
    }

    for(int i=0 ; i<size ; i++) {
        min = tc[i];
        num = (int*)malloc(sizeof(int) * (2*min+1));
        for(int j=2 ; j<=2*min ; j++)
            num[j] = j;
        for(int j=2 ; j<=2*min ; j++) {
            if(num[j] == 0) continue;
            for(int k=j+j ; k<=2*min ; k+=j)
                num[k] = 0;
        }
        for(int j=min+1 ; j<=2*min ; j++) {
            if(num[j] != 0) prime++;
        }
        printf("%d\n", prime);
        free(num);
        prime = 0;
    }
    free(tc);
    return 0;
}