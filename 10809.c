/*
 * Q.10809 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <string.h>

#define ISERROR -1 // input string error, 소문자 이외의 문자가 입력으로 들어온 경우에 대한 예외처리

// 함수 선언부
int idxCheck(char c); // 입력으로 들어온 소문자 알파벳에 대한 alist의 인덱스 값을 반환해주는 함수

int main()
{
    char s[100]; // 알파벳 소문자로만 이뤄진 문자열 S를 저장하는 char 배열
    int alist[26]; // 각 알파벳별 인덱스 값을 저장하는 정수형 배열

    // 0. alist의 모든 원소를 -1로 초기화
    for(int i=0 ; i<26 ; i++)
        alist[i] = -1;

    // 1. 소문자로만 구성된 문자열 S를 입력받음(+예외처리)
    scanf("%s", s);
    // 1-1. 소문자 이외의 문자가 입력된 경우에 대한 예외처리
    for(int i=0 ; i<strlen(s) ; i++) {
        if(!(s[i]>=97 && s[i]<=122)) {
            printf("Error! - invalid input string.\n");
            return ISERROR;
        }
    }

    // 2. 입력받은 문자열 S를 분석하여 결과값을 반영
    for(int i=0 ; i<strlen(s) ; i++) {
        // 발견되지 않았던 알파벳인 경우
        if(alist[idxCheck(s[i])] == -1)
            alist[idxCheck(s[i])] = i;
    }

    // 3. 결과값을 출력
    for(int i=0 ; i<26 ; i++)
        printf("%d ", alist[i]);
    printf("\n");
    return 0;
}

// 함수 정의부
int idxCheck(char c)
{
    return c-97;
}