/*
 * Q.2839 Solution Source Code
 * Writer : JuyoungIt
 */

#include<stdio.h>

int main()
{
    int n;        // the weight of sugar(kg)
    int num = -1; // the number of sugar bags
    int remain;

    scanf("%d", &n);
    for(int i=0 ; i<=n/5 ; i++) {
        remain = n - 5*i;
        if(remain%3 != 0) {
            if(num != -1)
                continue;
            else
                num = -1;
        }
        else
            num = i + remain/3;
    }
    printf("%d\n", num);
    return 0;
}