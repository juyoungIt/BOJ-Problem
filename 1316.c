/*
 * Q.1316 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main()
{
    // 0. 변수 선언
    int wordCount; // 단어의 갯수
    int curCount = 0; // 현재까지 입력된 단어의 갯수
    char tmpStr[100+1]; // 입력 문자열을 임시저장
    char** wordCase; // 입력되는 단어들을 저장하는 포인터 배열
    char curChar = -1; // 현재 조회중인 문자 임시저장
    char preChar = -1; // 이전에 조회한 문자 임시저장
    int gpCount = 0; // 그룹 단어의 갯수
    char alCount[26] = {FALSE}; // 각 알파벳의 등장여부를 저장하는 배열
    int j=0; // 반복문 변수
    int len; // 입력 문자열의 길이

    // 1. 단어의 개수 입력(+ 예외처리)
    scanf("%d", &wordCount);
    // 예외처리 - 단어의 개수가 유효한 범위가 아닌 경우
    if(wordCount<1 || wordCount>100) {
        printf("Error! - invalid word count range.\n");
        return -1;
    }

    // 2. 각 단어 입력(+ 예외처리)
    wordCase = (char**)malloc(sizeof(char*)*wordCount); // 입력 단어를 저장하는 포인터 배열
    for(int i=0 ; i<wordCount ; i++) {
        scanf("%s", tmpStr); // 입력단어 임시저장
        // 예외처리1 - 입력 단어의 길이 범위가 유효하지 않은 경우
        len = (int)strlen(tmpStr);
        if(len<0 || len>100) {
            printf("Error! - invalid input string length.\n");
            return -2;
        }
        // 예외처리2 - 입력 문자열이 알파벳 소문자 이외의 문자를 포함하는 경우
        for(int k=0 ; k<len ; k++) {
            if(tmpStr[k]<97 || tmpStr[k]>122) {
                printf("Error! - input string include invalid character.\n");
                return -3;
            }
        }
        // 예외처리3 - 입력 문자열이 이전에 입력된 적이 있는 문자열인 경우
        for(int k=0 ; k<curCount ; k++) {
            if(strcmp(wordCase[k], tmpStr) == 0) {
                printf("Error! - duplicated input string was detected.\n");
                return -4;
            }
        }
        wordCase[i] = (char*)malloc(sizeof(char)*len); // 단어를 저장할 char형 배열공간 할당
        strcpy(wordCase[i], tmpStr); // 단어 입력
        curCount++; // 현재 입력된 단어의 수를 1증가
    }

    // 3. 그룹 단어의 수를 카운트
    // 단어 단위 접근
    for(int i=0 ; i<wordCount ; i++) {
        // 단어를 구성하는 문자단위 접근
        for(j=0 ; j<(int)strlen(wordCase[i]) ; j++) {
            curChar = wordCase[i][j]; // 1개의 단어를 불러옴
            // 처음 등장한 단어인 경우
            if(alCount[curChar-97] == FALSE)
                alCount[curChar-97] = TRUE; // 등장한 알파벳 정보를 업데이트
            // 등장한 이력이 있는 단어인 경우
            else {
                // 연속되는 경우가 아닌 경우
                if(preChar != curChar) break;
            }
            preChar = curChar; // 현재 조회 중인 문자를 백업
        }
        // 모든 구성 문자들이 그룹으로 구성된 경우
        if(j == (int)strlen(wordCase[i])) gpCount++; // 그룹문자 카운트 수를 1증가
        // 재사용을 위해 관련 변수들 초기화
        preChar = -1;
        curChar = -1;
        for(int k=0 ; k<26 ; k++)
            alCount[k] = FALSE;
    }

    // 4. 산출결과를 출력
    printf("%d\n", gpCount);

    // 5. 프로그램 종료
    return 0;
}