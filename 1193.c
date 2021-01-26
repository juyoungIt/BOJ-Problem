/*
 * Q.1193 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int x; // input number X
    int top, bottom; // "top number / bottom number"
    int op; // "-1 : '-', 1 : '+'"
    int maxVal; // maximum value of each loop

    top = 1;
    bottom = 1;

    scanf("%d", &x);
    // calculate top number
    op = -1;
    maxVal = 1;
    for(int i=1 ; i<x ; i++) {
        if(op == -1 && top == 1) {
            maxVal++;
            op *= -1;
        }
        else if(op == 1 && top == maxVal) {
            maxVal++;
            top = maxVal;
            op *= -1;
        }
        else {
            if(op == 1)
                top++;
            else
                top--;
        }
    }
    // calculate bottom number
    op = 1;
    maxVal = 1;
    for(int i=1 ; i<x ; i++) {
        if(op == 1 && bottom == maxVal) {
            maxVal++;
            bottom = maxVal;
            op *= -1;
        }
        else if(op == -1 && bottom == 1) {
            maxVal++;
            op *= -1;
        }
        else {
            if(op == 1)
                bottom++;
            else
                bottom--;
        }
    }
    printf("%d/%d\n", top, bottom);
    return 0;
}