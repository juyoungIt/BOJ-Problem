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
    int count;

    scanf("%d %d", &min, &max);
    count = max-min+1;
    num = (int*)malloc(sizeof(int) * count);
    for(int i=min ; i<=max ; i++)
        num[i] = i;

    /*
     * Solution Algorithm here...
     */

    for(int i=0 ; i<count ; i++) {
        if(num[i] == 0) continue;
        printf("%d\n", num[i]);
    }
    return 0;
}