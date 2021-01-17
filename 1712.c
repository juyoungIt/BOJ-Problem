/*
 * Q.1712 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

#define MIN 1           // 입력값의 최솟값
#define MAX 2100000000  // 입력값의 최댓값

// 함수 선언부
int validCheck(int a, int b, int c); // 입력된 값의 유효성 판단
int findPoint(int a, int b, int c); // 손익분기점을 찾음

int main()
{
    // 0. 변수선언
    int fix;   // 고정비용(A)
    int var;   // 가변비용(B)
    int prod;  // 제품가격(C)
    int sell;  // 반복문 변수, 판매한 제품의 수
    int check; // 입력된 수에 대한 유효성 체크확인 결과

    // 1. 고정/가변비용, 제품가격 입력
    scanf("%d %d %d", &fix, &var, &prod);
    check = validCheck(fix, var, prod);
    // 입력값의 범위가 잘못된 경우
    if(check == -1) {
        printf("Error! - invalid input value range.\n");
        return -1;
    }

    // 2. 손익분기점 계산
    sell = findPoint(fix, var, prod);

    // 3. 결과출력
    printf("%d\n", sell);

    // 4. 프로그램 종료
    return 0;
}

// 함수 정의부

int validCheck(int a, int b, int c)
{
    // 3개의 인자중 하나라도 범위를 만족하지 않는 경우
    if(a<MIN || a>MAX || b<MIN || b>MAX || c<MIN || c>MAX)
        return -1;
    return 1; // 3개의 인지가 유효한 입력인 경우
}

int findPoint(int a, int b, int c)
{
    int i = 0; // 반복문 변수

    // 손익분기점이 발생할 수 없는 조합인 경우
    if(b >= c)
        return -1;
    // 손익분기점을 계산
    else
        return a/(c-b)+1;
}