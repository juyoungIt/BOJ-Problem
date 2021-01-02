/*
 * Q.8958 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tcCount; // 테스트 케이스의 갯수
    int tcLen; // 테스트 케이스의 길이
    char temp[80]; // 테스트 케이스를 임시저장
    char** testCase; // 테스트 케이스를 저장하는 포인터 배열
    int* result; // 테스트 케이스 점수를 저장하는 정수형 배열
    int weight = 1; // 점수 계산을 위해서 사용하는 가중치 값(연속되는 O 누적값)
    int score = 0; // 테스트 케이스의 점수

    // 1. test case의 갯수를 입력받음
    scanf("%d", &tcCount);

    // 2. test case를 입력받음
    testCase = (char**)malloc(sizeof(char**)*tcCount); // 테스트 케이스들을 저장하는 배열을 동적할당(리스트)
    for(int i=0 ; i<tcCount ; i++)
    {
        scanf("%s", temp); // 테스트 케이스를 사용자로부터 입력받음
        *(testCase+i) = (char*)malloc(sizeof(char)*strlen(temp)); // 테스트 케이스를 저장하는 배열을 동적할당트(하나)
        strcpy(*(testCase+i), temp); // 입력받은 문자열을 입력함

        // 입력되는 test case의 길이에 대한 예외처리
        tcLen = strlen(*(testCase+i)); // 입력된 테스트 케이스의 길이를 구함
        if((tcLen <= 0) || (tcLen >= 80))
        {
            printf("Error! : invalid test case length!\n");
            return -1; // 테스트 케이스 길이의 오류를 의미하는 -1을 반환하며 프로그램 종료
        }
        // O,X 이외의 문자가 입력된 경우에 대한 예외처리
        for(int i=0 ; i<tcLen ; i++)
        {
            if(!(temp[i] == 'O' || temp[i] == 'X'))
            {
                printf("Error! : invalid test case input - other char detected.\n");
                return -2; // 테스트 케이스에 O,X 이외의 문자가 입력된 오류를 의미하는 -2를 반환하며 프로그램 종료
            }
        }
    }

    // 3. 각 테스트 케이스의 점수를 계산하여 배열에 저장함
    result = (int*)malloc(sizeof(int)*tcCount); // 점수를 저장할 배열을 위한 메모리 공간 동적할당
    for(int i=0 ; i<tcCount ; i++)
    {
        // 테스트 케이스의 점수를 계산함
        for(int j=0 ; j<strlen(*(testCase+i)) ; j++)
        {
            // 문자가 O인 경우
            if(*(*(testCase+i)+j) == 'O')
            {
                score += weight;
                weight++; // weight의 값을 1증가
            }
            // 문자가 X인 경우
            else
            {
                weight = 1; // X를 만나면 weight의 값을 1로 초기화
            }
        }
        result[i] = score; // 산출한 점수값을 저장함.
        score = 0; // 다음 회차에서의 재사용을 위해 score 값 초기화
        weight = 1; // 다음 회차에서의 재사용을 위해 weight 값 초기화
    }

    // 4. 구한 점수값을 출력
    for(int i=0 ; i<tcCount ; i++)
        printf("%d\n", result[i]);

    // 5. 동적할당했던 메모리 공간을 해제
    for(int i=0 ; i<tcCount ; i++)
        free(*(testCase+i)); // 각 테스트에 대한 메모리 공간해제
    free(testCase); // 테스트 케이스를 저장하는 배열에 대한 메모리 공간해제
    free(result); // 결과값을 저장하는 배열에 대한 메모리 공간해제

    return 0;
}