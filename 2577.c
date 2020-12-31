/*
 * Q.2577 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int number[3]; // 사용자가 입력하는 3개의 자연수를 저장하는 정수형 배열 (A,B,C)
    int count[10] = {0}; // 각 숫자별 식별 횟수를 저장하는 정수형 배열
    int result = 1; // 사용자에게 입력받은 3개의 정수의 곱셈결과 값

    // 3개의 자연수를 입력받는 부분
    for(int i=0 ; i<3 ; i++)
    {
        scanf("%d", &number[i]);
        // 입력 값의 범위에 대한 예외처리
        if((number[i] < 100) || (number[i] >= 1000))
        {
            printf("Error! : invalid input value range!\n");
            return -1; // 입력값의 범위오류를 의미하는 -1을 반환하며 프로그램 종료
        }
    }

    // 곱셈 연산을 수행하는 부분
    for(int i=0 ; i<3 ; i++)
        result *= number[i];

    // 곱셈결과로부터 각 숫자가 나타나는 횟수를 카운트
    while(1)
    {
        // 0. result 값이 0이 된 경우 반복문을 빠져나옴
        if(result == 0) break;
        // 1. 일의 자리 수를 구하고 해당 수를 판단하여 카운트 수를 1증가
        count[result%10]++;
        // 2. result 값을 다음 반복회차에서 사용할 수 있도록 업데이트
        result /= 10;
    }

    // 카운트 결과를 출력
    for(int i=0 ; i<10 ; i++)
        printf("%d\n", count[i]);

    return 0;
}