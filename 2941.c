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
    int result = 0; // 크로아티아 알파벳의 수

    for(int i=0 ; i<len ; i++) {
        // 'c=' 문자를 만난 경우
        if(str[i] == 'c' && str[i+1] == '=') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 'c-' 문자를 만난 경우
        else if(str[i] == 'c' && str[i+1] == '-') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 'dz=' 문자를 만난 경우
        else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '=') {
            result++;
            i += 2; // 다음 단어가 위치한 인덱스로 넘어감
        }
        // 'd-' 문자를 만난 경우
        else if(str[i] == 'd' && str[i+1] == '-') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 'lj' 문자를 만난 경우
        else if(str[i] == 'l' && str[i+1] == 'j') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 'nj' 문자를 만난 경우
        else if(str[i] == 'n' && str[i+1] == 'j') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 's=' 문자를 만난 경우
        else if(str[i] == 's' && str[i+1] == '=') {
            result++;
            i++; // 다음 인덱스로 넘어감
        }
        // 그 외의 일반 알파벳인 경우
        else if(str[i]>=97 && str[i]<=122) result++;
    }
    return result;
}