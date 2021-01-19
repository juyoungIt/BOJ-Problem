/*
 * Q.10870 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

// 함수 선언부
int fiboNum(int n); // n번째 피보나치 수를 구함

int main()
{
    int n; // 구하고자 하는 n번째
    int result; // n번째의 피보나치 수

    scanf("%d", &n);
    result = fiboNum(n);
    printf("%d\n", result);
    return 0;
}

// 함수 정의부
int fiboNum(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fiboNum(n-2) + fiboNum(n-1);
}