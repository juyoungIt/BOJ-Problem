/*
 * Q.11654 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

#define INPUTERROR -1
#define TRUE 1
#define FALSE 0

// 함수 선언부
int checkLetter(int letter); // 입력받은 아스키코드 기반 문자가 알파벳 소/대문자, 0~9중 1개의 수인지를 검사

int main()
{
    int letter; // 사용자로부터 입력받는 1개의 문자
    int validCheck; // 입력된 문자가 유효한 문자인지 확인

    // 1. 사용자로부터 알파벳 소문자, 대문자, 숫자 0~9중 1개의 수를 입력받음
    letter = getchar();
    validCheck = checkLetter(letter);
    if(validCheck == FALSE) {
        printf("Error! - invalid input value range!\n");
        return INPUTERROR;
    }

    // 2. 입력받은 문자의 아스키코드 값을 출력
    printf("%d\n", letter);
    return 0;
}

// 함수 정의부
int checkLetter(int letter)
{
    // 0~9 사이의 숫자인지에 대한 여부를 검사하는 부분
    if((letter>=48) && (letter<=57)) return TRUE;
    // 알파벳 소문자 인지에 대한 여부를 검사하는 부분
    else if((letter>=65) && (letter<=90)) return TRUE;
    // 알파벳 대문자 인지에 대한 여부를 검사하는 부분
    else if((letter>=97) && (letter<=122)) return TRUE;
    // 그 이외의 경우
    else return FALSE;
}