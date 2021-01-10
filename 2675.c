/*
 * Q.2675 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1  // 참을 의미하는 상수
#define FALSE 0 // 0을 의미하는 상수

#define TCRANGEERROR -1 // 테스트 케이스의 범위가 오류가 있음을 의미하는 상수
#define TCREPERROR -2 // 테스트의 반복횟수 값의 범위가 오류가 있음을 의미하는 상수
#define TCSTRLENERROR -3 // 테스트 케이스 문자열의 길이에 오류가 있음을 의미하는 상수

int main()
{
    int tcCount;      // 테스트 케이스의 갯수
    int temp;         // 정수값을 일시저장
    int* repCount;    // 문자 반복의 갯수를 저장하는 정수형 배열
    int rep;          // 반복횟수를 일시저장
    int len;          // 문자열의 길이를 임시저장
    char tmpStr[50];  // 문자열을 일시적으로 저장하는 char 배열
    char** testStr;   // 각 테스트 케이스의 문자열 s를 저장하는 포인터 배열
    char** resultStr; // 처리한 결과 str을 저장하는 포인터 배열
    int idx=0;          // 배열의 인덱스를 저장하는 정수형 변수

    // 1. 테스트 케이스의 갯수를 입력
    scanf("%d", &tcCount);
    // 1-1. 예외처리 - 1 ~ 1000 사이의 값이 테스트 케이스로 주어진 경우
    if(!(tcCount>=1 && tcCount<=1000)) {
        printf("Error! - invalid test case range.\n");
        return TCRANGEERROR;
    }
    // 2. 각 테스트 케이스별 반복 횟수와 문자열 S를 입력받음
    // 2-1. 필요한 메모리 공간 동적할당
    repCount = (int*)malloc(sizeof(int) * tcCount);      // 반복 횟수를 저장하는 정수형 배열 동적할당
    testStr = (char**)malloc(sizeof(char*) * tcCount);   // 테스트 케이스 문자열을 저장하기 위한 포인터 배열 할당
    resultStr = (char**)malloc(sizeof(char*) * tcCount); // 처리된 문자열들을 저장하는 포인터 배열 할당
    // 2-2. 초기에 입력받은 테스트 케이스의 수만큼 반복횟수와 문자열을 입력
    for(int i=0 ; i<tcCount ; i++) {
        // 2-2-1. 테스트 케이스의 반복횟수 입력
        scanf("%d", &temp);
        // 2-2-2. 예외처리 - 테스트 케이스 값의 범위가 1~8 사이의 이외의 값이 입력된 경우
        if(!(temp>=1 && temp<=8)) {
            printf("Error! - invalid test case repeat count value.\n");
            return TCREPERROR;
        }
        // 2-2-3. 정상적인 범위의 값이 반복횟수 값으로 들어온 경우
        else {
            repCount[i] = temp; // 반복횟수를 저장
        }
        // 2-2-4. 테스트 케이스의 문자열 s를 입력
        scanf("%s", tmpStr);
        // 2-2-5. 예외처리 - 입력된 테스트 케이스의 문자열 s가 유효한 길이값을 가지지 않는 경우
        len = (int)strlen(tmpStr); // 입력된 문자열 s의 길이를 가져옴
        // 사용자 입력 문자열 s가 1~20 범위 밖의 길이를 가지는 경우
        if(!(len>=1 && len<=20)) {
            printf("Error! - invalid test case string length error.\n");
            return TCSTRLENERROR;
        }
        testStr[i] = (char*)malloc(sizeof(char) * len + 1); // 문자열 s를 저장하기 위한 배열 동적할당
        strcpy(testStr[i], tmpStr); // 입력받은 문자열을 저장
    }

    // 3. 각 테스트 케이스 별 반복 횟수 만큼 각 자리의 문자를 반복하여 새로운 문자열을 생성
    for(int i=0 ; i<tcCount ; i++) {
        rep = repCount[i]; // 해당 회차 테스트 케이스의 반복값을 가져옴
        len = (int)strlen(testStr[i]); // 해당 테스트케이스의 문자열의 길이를 로딩
        // 3-1. 결과 문자열을 저장할 메모리 공간 동적할당
        resultStr[i] = (char*)malloc(sizeof(char) * len * rep + 1);
        // 3-2. 결과 문자열을 생성
        for(int j=0 ; j<len ; j++) {
            for(int k=0 ; k<rep ; k++) {
                resultStr[i][idx] = testStr[i][j];
                idx++; // 다음 접근을 위해서 인덱스의 값을 1증가
            }
        }
        idx=0 ;// 다음 회차에 재사용을 위한 인덱스값 초기화
    }

    // 4. 생성한 새로운 문자열을 출력
    for(int i=0 ; i<tcCount ; i++)
        printf("%s\n", resultStr[i]);

    // 5. 동적할당한 메모리 공간을 반납 및 프로그램 종료
    // 5-1. 각 테스트 케이스 별로 할당한 문자열 공간, 처리결과 문자열 공간 해제
    for(int i=0 ; i<tcCount ; i++) {
        free(testStr[i]);
        free(resultStr[i]);
    }
    // 5-2. 반복 횟수를 저장하는 정수형 배열 공간 해제
    free(repCount);
    // 5-3. 테스트 케이스, 처리결과 문자열들을 저장하는 포인터배열 공간 해제
    free(testStr);
    free(resultStr);

    // 6. 0을 반환하며 프로그램 종료
    return 0;
}