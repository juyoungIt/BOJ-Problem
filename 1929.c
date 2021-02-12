/*
 * Q.1929 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min, max; // store M, N value
    int* num;

    scanf("%d %d", &min, &max);
    num = (int*)malloc(sizeof(int) * (max+1));
    for(int i=2 ; i<=max ; i++)
        num[i] = i;

    for(int i=2 ; i<=max ; i++) {
        if(num[i] == 0) continue;
        for(int j=i+i ; j<=max ; j+=i)
            num[j] = 0;
    }

    for(int i=min ; i<=max ; i++)
        if(num[i] != 0) printf("%d\n", num[i]);
    free(num);
    return 0;
}