/*
 * Q.3052 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#define DIVIDER 42

int main()
{
    int num[10]; // 사용자에게 입력받는 10개의 자연수를 저장하는 배열
    int result[42]; // %연산의 결과값을 저장하는 정수형 배열
    int temp; // 연산결과값을 일시저장
    int size = 0; // 결과값을 저장하는 배열(result)의 길이값을 저장
    int j; // 반복문 변수

    // 사용자로부터 정수를 입력받는 부분
    for(int i=0 ; i<10 ; i++) {
        scanf("%d", &num[i]);
        // 입력값의 범위에 대한 예외처리
        if (num[i] < 0 || num[i] > 1000) {
            printf("Error! : invalid input value range!\n");
            return -1; // 입력값의 범위에서 오류가 발생했음을 의미하는 -1을 반환하며 프로그램 종료
        }
    }

    // 연산을 수행하여 결과값을 저장하는 부분
    for(int i=0 ; i<10 ; i++)
    {
        temp = num[i]%DIVIDER; // %연산을 수행
        // 결과를 저장하는 배열에 중복되는 값이 있는 지 판별하는 부분
        for(j=0 ; j<size ; j++)
        {
            // 중복되는 결과값이 존재하는 경우
            if(result[j] == temp) break;
        }
        // 중복되는 결과값이 존재하지 않는 경우
        if(j == size)
        {
            result[j] = temp; // 결과값을 배열에 추가
            size++; // size의 값을 1증가
        }
    }

    // 결과값을 출력하는 부분
    printf("%d\n", size);
    return 0;
}