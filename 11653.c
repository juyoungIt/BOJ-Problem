/*
 * Q.11653 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int num; // the input number 'N'
    int mid; // store middle value of operation

    scanf("%d", &num);
    mid = num;
    while(1) {
        if(mid == 1)
            break;
        for(int i=2 ; i<=mid ; i++) {
            if(mid%i == 0) {
                printf("%d\n", i);
                mid /= i;
                break;
            }
        }
    }
    return 0;
}