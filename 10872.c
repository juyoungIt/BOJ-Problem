/*
 * Q.10872 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

// 함수 선언부
int factorial(int n); // 입력된 n에 대한 n!값 출력

int main()
{
    // 0. 변수선언
    int n; // 입력 정수
    int result; // 계산결과

    // 1. 정수n 입력
    scanf("%d", &n);

    // 2. factorial 값 계산
    result = factorial(n);

    // 3. 결과출력
    printf("%d\n", result);

    // 4. 프로그램 종료
    return 0;
}

// 함수 정의부
int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}