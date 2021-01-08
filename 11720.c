/*
 * Q.11720 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGEERROR -1 // n값의 범위 오류를 의미하는 상수
#define STRINGERROR -2 // string을 구성하는 문자에 오류가 있음을 의미하는 상수
#define STRLENERROR -3 // string의 길이에 오류가 있음을 의미하는 상수

// 함수 선언부
int ctoi(char c); // 전달된 1개의 문자를 정수값으로 반환

int main()
{
    int n; // 숫자의 갯수
    char temp; // 문자열을 구성하는 각 문자의 아스키코드값
    char* str; // 입력받는 숫자들
    int sum = 0; // 총합값을 계산

    // 1. 숫자의 갯수 n을 입력받는 부분 (+ 예외처리)
    scanf("%d", &n);
    if(n<1 || n>100) {
        printf("Error! : invalid input value range!\n");
        return RANGEERROR;
    }
    // 2. 길이 N의 숫자로 구성된 문자열을 입력 (+예외처리)
    str = (char*)malloc(sizeof(char)*n); // 문자열을 저장한 배열공간 동적할당
    scanf("%s", str);
    // 예외처리1 - 문자열의 길이가 N만큼 입력되지 않은 경우
    if(strlen(str) != n) {
        printf("Error! - invalid string length.\n");
        return STRLENERROR;
    }
    // 예외처리2 - 숫자가 아닌 다른 문자가 입력된 경우
    for(int i=0 ; i<n ; i++) {
        temp = *(str+i);
        if(!(temp>=48 && temp<=57)) {
            printf("Error! - invalid string letter.\n");
            return STRINGERROR;
        }
    }
    // 3. 문자열을 구성하는 각 문자들을 숫자로 변환하여 총합을 계산
    for(int i=0 ; i<n ; i++) {
        sum += ctoi(*(str+i));
    }
    // 4. 산출한 결과값을 출력 및 동적할당 메모리공간 해제
    printf("%d\n", sum);
    free(str);
    return 0;
}

// 함수 정의부
int ctoi(char c)
{
    return c-48;
}