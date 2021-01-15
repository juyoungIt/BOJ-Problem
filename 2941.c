/*
 * Q.2941 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// 함수 선언부
int validCheck(char* str, int len); // 입력 문자열의 유효성 검사
int alCount(char* str, int len);    // 문자열에 존재하는 크로아티아 문자수 카운트
int isStart(char c); // 입력문자가 특수문자를 시작하는 문자인지 판별
int isEnd(char c); // 입력문자가 특수문자를 마무리하는 문자인지 판별

int main()
{
    // 0. 필요한 변수선언
    char str[100+1]; // 입력 문자열
    int result; // 크로아티아 문자 수
    int len; // 입력 문자열의 길이

    // 1. 문자열 입력 (+ 유효성 검사)
    scanf("%s", str);
    len = (int)strlen(str);
    if(validCheck(str, len) == FALSE) {
        printf("Error! - invalid string input.\n");
        return -1;
    }

    // 2. 크로아티아 문자의 수 카운트
    result = alCount(str, len);

    // 3. 카운트 결과를 출력
    printf("%d\n", result);

    // 4. 프로그램 종료
    return 0;
}

// 함수 정의부
int validCheck(char* str, int len)
{
    char tmp; // 현재 조회 중인 문자
    for(int i=0 ; i<len ; i++) {
        tmp = str[i]; // 문자 1개 읽기
        if(!((tmp>=97 && tmp<=122) || tmp == '-' || tmp == '='))
            return FALSE;
    }
    return TRUE;
}

int alCount(char* str, int len)
{
    char cur; // 현재 조회하는 문자
    char prev; // 이전에 조회한 문자
    char special = FALSE; // 특수문자 리딩상태 여부
    int count = 0; // 문자열에 존재하는 알파벳 카운트의 수

    for(int i=0 ; i<len ; i++) {
        cur = str[i]; // 문자 1개 로딩
        // 특수문자를 읽고 있는 상황인 경우
        if(special == TRUE) {
            // 특수문자를 마무리하는 문자인 경우
            if(isEnd(cur)) {
                // 현재 문자가 '-'인 경우
                if(cur == '-') {
                    // 이전문자가 'c' 또는 'd'
                    if(prev == 'c' || prev == 'd') {
                        count++; // 알파벳 수 1증가
                        special = FALSE; // 특수문자 리딩상태 업데이트
                    }
                }
                // 현재 문자가 '='인 경우
                else if(cur == '=') {
                    // 이전 문자가 'c' 또는 'z' 또는 's'인 경우
                    if(prev == 'c' || prev == 'z' || prev == 's') {
                        count++; // 알파벳 수 1증가
                        special = FALSE; // 특수문자 리딩상태 업데이트
                    }
                }
                // 현재 문자가 'j'인 경우
                else if(cur == 'j') {
                    // 이전 문자가 'l' 또는 'n'인 경우
                    if(prev == 'l' || prev == 'n') {
                        count++; // 알파벳 수 1증가
                        special = FALSE; // 특수문자 리딩상태 업데이트
                    }
                }
            }
            // 특수문자를 마무리하는 문자가 아닌 경우
            else {
                // 특수문자를 시작하는 문자인 경우
                if(isStart(cur)) {
                    // 이전문자가 d, 현재문자가 z가 아닌 경우
                    if(!(prev == 'd' && cur == 'z')) {
                        count++; // 알파벳 수 1증가
                    }
                }
                // 특수문자를 시작하는 문자가 아닌 경우
                else {
                    count += 2; // 알파벳 수 2증가
                    special = FALSE; // 특수문자 리딩 상태 업데이트
                }
            }
        }
        // 특수문자를 리딩하는 상황이 아닌 경우
        else {
            // 특수문자를 시작하는 문자인 경우
            if(isStart(cur)) {
                special = TRUE; // 특수문자 리딩상태 업데이트
            }
            // 특수문자를 시작하는 문자가 아닌 경우
            else {
                count++; // 알파벳의 수 1증가
            }
        }
        prev = cur; // 현재 조회 중인 문자를 백업
    }
    return count; // 산출한 카운트 결과 반환
}

int isStart(char c)
{
    if(c == 'c' || c == 'd' || c == 'l' || c == 'n' || c == 's' || c == 'z')
        return TRUE;
    else
        return FALSE;
}

int isEnd(char c)
{
    if(c == '-' || c == '=' || c == 'j')
        return TRUE;
    else
        return FALSE;
}