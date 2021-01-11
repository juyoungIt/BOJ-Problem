/*
 * Q.1152 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000000

// 함수 선언부
int strValid(char*); // 입력된 문자열의 유효성을 판단 (1 - 문제없음, 0 - 문제있음)
int spaceCheck(char*); // 입력된 문자열의 앞뒤 공백 존재 여부 확인 (0 - 앞에만, 1 - 뒤에만, 2 - 둘다)
int spaceCount(char*); // 문자열 내에 존재하는 space의 갯수를 카운트하여 반환

int main()
{
    char str[MAXSIZE+2]; // 입력 문자열
    int wordCount = 0; // 단어의 갯수
    int validCheck; // 문자열의 유효성 판정결과
    int spLocation; // 문자열 앞, 뒤의 공백 존재 여부
    int space; // 문자열에 존재하는 space의 수

    // 1. 문자열 입력 및 저장 (+예외처리)
    fgets(str, MAXSIZE+2, stdin);
    // 1-1. 입력된 문자열의 유효성 검사
    validCheck = strValid(str);
    if(validCheck == FALSE) {
        printf("Error! - invalid input string.\n");
        return -1;
    }

    // 2. 문자열 앞, 뒤에 space 존재유뮤 판별
    spLocation = spaceCheck(str);

    // 3. 문자열 내에 존재하는 space의 갯수 카운트
    space = spaceCount(str);

    // 4. 문자열에 존재하는 단어의 갯수 카운트
    // 문자열의 앞뒤에 space가 존재하지 않는 경우
    if(spLocation == 0) wordCount = space + 1;
    // 문자열의 앞에만 space or 문자열의 뒤에만 space
    else if(spLocation == 1) wordCount = space;
    // 문자열의 앞, 뒤에 모두 space가 존재하는 경우
    else if(spLocation == 2) wordCount = space - 1;
    // 입력된 문자가 존재하지 않는 경우
    else wordCount = 0;

    // 5. 산출결과 출력
    printf("%d\n", wordCount);
    return 0;
}

// 함수 정의부
int strValid(char* str)
{
    char tmp; // 1개의 문자 임시저장

    // 문자열의 구성 문자에 대한 검사
    for(int i=0 ; i<(int)strlen(str) ; i++) {
        tmp = str[i]; // 1개의 문자를 읽어옴
        // 문자가 알파벳 대소문자, space 이외의 문자인 경우
        if(!((tmp>=65 && tmp<=90) || (tmp>=97 && tmp<=122) || (tmp == 32) || (tmp == '\n'))) {
            printf("The letter %c is detected.\n", tmp);
            return FALSE;
        }
    }
    return TRUE;
}

int spaceCheck(char* str)
{
    int result=0; // 확인결과
    char front = str[0]; // 문자열의 가장 첫번째 문자를 읽어옴
    char back = str[strlen(str)-2]; // 문자열의 가장 마지막 문자를 읽어옴
    int len = (int)strlen(str); // 문자열의 길이

    // 1. 문자열의 가장 첫번째 문자가 space인 경우
    if(front == 32) result++;
    // 2. 문자열의 가장 마지막 문자가 space인 경우
    if(back == 32) result++;
    // 3. 입력된 문자없이 빈 문자열이 입력된 경우 - '\n'문자만 포함하여 길이가 1
    if(len == 1) result = -1;
    return result;
}

int spaceCount(char* str)
{
    int result = 0; // 카운트 결과값을 저장

    for(int i=0 ; i<(int)strlen(str) ; i++) {
        if(str[i] == 32)
            result++;
    }
    return result;
}