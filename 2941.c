/*
 * Q.2941 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

// 함수 선언부
int validCheck(char* str, int len); // 입력 문자열에 대한 유효성 검사
int specialChar(char c); // 특수한 문자를 구성하는 문자인지 여부를 판별
int alCount(char* str, int len); // 입력 문자열을 구성하는 크로아티아 알파벳의 수를 카운트

int main()
{
    char str[MAXSIZE+1]; // 입력 문자열
    int len; // 입력 문자열의 길이
    int count; // 크로아티아 알파벳의 수

    // 1. 문자열 입력 + 유효성 검사
    scanf("%s", str);
    len = (int)strlen(str);
    if(validCheck(str, len) == FALSE) {
        printf("Error! - invalid input string.\n");
        return -1;
    }

    // 2. 크로아티아 알파벳의 수를 카운트함
    count = alCount(str, len);

    // 3. 카운트 결과를 출력
    printf("%d\n", count);

    // 4. 프로그램을 종료
    return 0;
}

// 함수 정의부
int validCheck(char* str, int len)
{
    char tmp; // 문자 1개를 임시저장

    for(int i=0 ; i<len ; i++) {
        tmp = str[i]; // 문자 1개를 읽어옴
        if(!((tmp>=97 && tmp<=122) || tmp == '-' || tmp == '='))
            return FALSE;
    }
    return TRUE;
}

int alCount(char* str, int len)
{
    int result = 0; // 카운트된 크로아티아 알파벳의 수
    int special = FALSE; // 특수문자를 읽는 중인지에 대한 여부
    char biprev = -1; // 이전이전 문자를 임시저장
    char prev = -1; // 이전 문자를 임시저장
    char cur; // 문자 1개를 임시저장

    for(int i=0 ; i<len ; i++) {
        cur = str[i]; // 1개의 문자를 가져옴
        // 특수한 경우를 제외한 일반적인 1자의 알파벳인 경우
        if(specialChar(cur) == FALSE) {
            if(special == FALSE)
                result++;
            else {
                special = FALSE;
                if(biprev == 'b' && prev == 'z') result += 3;
                else result += 2;
            }
        }
        // 특수한 경우인 2자 또는 3자 알파벳을 구성하는 알파벳인 경우
        else {
            special = TRUE;
            if((prev == 'c' && cur == '=') || (prev == 'c' && cur == '-')) result++;
            else if(prev == 'd' && cur == '-') result++;
            else if((prev == 'l' && cur == 'j') || (prev == 'n' && cur == 'j')) result++;
            else if((prev == 's' && cur == '=') || (prev == 'z' && cur == '=')) result++;
            else if(biprev == 'b' && prev == 'z' && cur == '=') result++;
        }
        biprev = prev; // 이전 문자를 백업
        prev = cur;    // 현재 문자를 백업
    }
    return result;
}

int specialChar(char c)
{
    if(c == 'c' || c == 'd' || c == 'l' || c == 'n' || c == 's' || c == 'z' || c == '-' || c == '=' || c == 'j')
        return TRUE;
    else
        return FALSE;
}