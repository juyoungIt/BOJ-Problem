/*
 * Q.4673 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#define INPUTERROR -1
#define TRUE 1
#define FALSE 0

// 함수 선언부
int selfNumber(int max); // max 이하 범위의 self number를 출력하는 함수
int d_result(int n);    // 인자로 받은 수의 d(n) 값을 출력하는 함수

int main()
{
    int result; // 함수의 처리결과를 저장하는 정수

    result = selfNumber(10000); // 10000까지의 self number를 구하는 함수를 호출
    // 인자의 범위가 잘못된 경우에 대한 예외처리
    if(result == INPUTERROR)
        return INPUTERROR; // input value range error를 의미하는 -1을 반환하며 프로그램 종료
    return 0; // 프로그램을 종료
}

// 함수 정의부
int selfNumber(int max)
{
    int i=1; // 반복문 변수
    int idx; // 배열의 인덱스 값
    int snArr[10001] = {FALSE}; // 1 ~ 10000 사이 수의 self number T/F를 저장하는 배열

    // 인자로 전달받은 값에 대한 예외처리
    if(max <= 0) {
        printf("Error! : invalid input value range!\n");
        return INPUTERROR;
    }

    // self number를 판별하여 그 결과를 배열에 업데이트
    while(1) {
        idx = d_result(i);
        if(i > max) break; // 10000보다 큰 self number가 등장한 경우 -> 반복을 종료
        if(idx > max) {
            i++;
            continue;
        }
        snArr[idx-1] = TRUE; // self number가 존재하는 위치에 대한 정보를 업데이트
        i++; // 다음 회차 반복을 위한 반복문 변수의 값을 1증가
    }

    // 이전 단계에서 구한 배열을 바탕으로 self number가 아닌 수를 출력
    for(int n=0 ; n<max ; n++) {
        if(snArr[n] == FALSE)
            printf("%d\n", n+1);
    }
    return 0;
}

// 인자로 받은 수의 d(n)값을 출력하는 함수
int d_result(int n)
{
    int result = 0; // 반환한 결과값
    int temp = n; // 연산에 사용하는 중간값을 임시저장
    // 1. 자기 자신을 더함
    result += temp;
    // 2. 각 자리 수를 더함
    while(1) {
        // temp 값이 0이 된 경우 - 연산을 종료(모든 자리 수를 더한 것이므로)
        if(temp == 0) break;
        result += temp%10; // 1의 자리 수를 더함
        temp /= 10; // 다음번 1의 자리 수를 구하기 위해 temp 값을 갱신
    }
    return result; // 결과값을 반환
}