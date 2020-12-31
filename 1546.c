/*
 * Q.1546 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testCount; // 응시한 시험 과목의 수
    double* testScore; // 응시한 시험 과목의 각 점수를 저장하는 배열 (동적할당)
    double max = -1; // 입력된 시험점수 중 최대값
    double sum = 0; // 각 과목 점수의 총합
    double ave; // 각 과목 점수의 평균

    // 1. 응시한 시험 과목의 수, 각 과목의 점수를 입력받음
    scanf("%d", &testCount);
    // 1-1. 입력된 과목의 수 값의 범위가 문제가 없는 지 확인
    if(testCount<1 || testCount > 1000) {
        printf("Error! : invalid testCount value range!\n");
        return -1; // 응시 과목 수 범위 오류를 의미하는 -1 반환 후 프로그램 종료
    }
    testScore = (double*)malloc(sizeof(double)*testCount); // 응시과목 점수를 저장하는 배열 동적할당
    for(int i=0 ; i<testCount ; i++)
    {
        scanf("%d", testScore+i);
        // 입력된 과목의 점수 값의 범위가 문제가 없는 지 확인
        if(*(testScore+i) < 0 || *(testScore+i)>100)
        {
            printf("Error! : invalid test score value range!\n");
            return -2; // 응시과목 점수 값의 범위 오류를 의미하는 -2 반환 후 프로그램 종류
        }
    }

    // 2. 입력된 시험점수 중 최대값을 구함.
    for(int i=0 ; i<testCount ; i++)
    {
        if(max < testScore[i])
            max = testScore[i];
    }

    // 3. 2에서 구한 최댓값을 바탕으로 새로운 점수값을 계산하여 업데이트
    for(int i=0 ; i<testCount ; i++)
        testScore[i] = testScore[i] / max * 100;

    // 4. 업데이트된 점수 값의 총합 및 평균계산
    for(int i=0 ; i<testCount ; i++)
        sum += testScore[i];
    ave = sum / testCount;

    // 5. 구한 평균값을 출력
    printf("%f\n", ave);

    // 6. 동적할당한 메모리 공간을 해제
    free(testScore);

    return 0;
}