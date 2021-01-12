/*
 * Q.5622 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXSIZE 15
#define STRERROR -1

// 함수 선언부
int validCheck(char* str); // 입력된 문자열의 제약조건을 확인하여 결과반환
int calTime(char* str); // 입력하는 데 소요되는 시간을 계산하여 반환

int main()
{
    char str[MAXSIZE+1]; // 사용자 입력 문자열 (null 문자가 들어갈 공간 1개 추가확보)
    int result; // 필요한 시간

    // 1. 문자열 입력, 유효성 검사
    scanf("%s", str);
    if(validCheck(str) == FALSE) {
        printf("Error! - invalid string input.\n");
        return STRERROR;
    }
    // 2. 소요시간 계산
    result = calTime(str);

    // 3. 산출결과 출력
    printf("%d\n", result);

    // 4. 프로그램 종료
    return 0;
}

// 함수 정의부
int validCheck(char* str)
{
    int len = (int)strlen(str); // 인자로 받은 문자열의 길이
    char tmp; // 문자열을 구성하는 문자를 일시저장
    // 1. 문자열의 길이 확인
    if(len<2 || len>15) return FALSE;
    // 2. 대문자로만 구성되어 있는 지 확인
    for(int i=0 ; i<len ; i++) {
        tmp = str[i];
        if(tmp<65 || tmp>90) return FALSE;
    }
    return TRUE;
}

int calTime(char* str)
{
    int result = 0; // 소요시간
    int len = (int)strlen(str); // 인자로 받은 문자열의 길이를 구함
    char tmp; // 문자열을 구성하는 문자

    for(int i=0 ; i<len ; i++) {
        tmp = str[i]; // 문자열을 구성하는 1개의 문자를 가져옴
        // A~C 문자인 경우
        if(tmp>=65 && tmp<=67)
            result += 3;
        // D~F 문자인 경우
        else if(tmp>=68 && tmp<=70)
            result += 4;
        // G~I 문자인 경우
        else if(tmp>=71 && tmp<=73)
            result += 5;
        // J~L 문자인 경우
        else if(tmp>=74 && tmp<=76)
            result += 6;
        // M~O 문자인 경우
        else if(tmp>=77 && tmp<=79)
            result += 7;
        // P~S 문자인 경우
        else if(tmp>=80 && tmp<=83)
            result += 8;
        // T~V 문자인 경우
        else if(tmp>=84 && tmp<=86)
            result += 9;
        // W~Z 문자인 경우
        else if(tmp>=87 && tmp<=90)
            result += 10;
        else
            continue;
    }
    return result;
}