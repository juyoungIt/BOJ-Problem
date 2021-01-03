/*
 * Q.4344 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

#define TCCERROR -1    // 테스트 케이스 수 범위의 오류를 의미하는 상수
#define SCERROR -2     // 학생 수 범위의 오류를 의미하는 상수
#define SCOREERROR -3  // 점수 범위의 오류를 의미하는 상수

int main()
{
    // 0. 필요한 변수들을 선언하는 부분
    int tcCount;    // 테스트 케이스의 수
    int** testCase; // 테스트 케이스를 저장하는 포인터 배열
    int* stdCount;  // 학생의 수를 저장하는 정수형 배열의 포인터
    int sum = 0; // 입력된 점수의 총합
    double* ave; // 테스트 케이스에 입력된 점수의 평균을 저장하는 정수형 배열의 포인터
    int upperCount = 0; // 평균보다 큰 점수를 가지는 수의 갯수
    double ratio; // 평균보다 높은 점수의 비율

    // 1. 관련 데이터를 입력받는 부분
    // 1-1. 테스트 케이스의 수 입력 + 예외처리
    scanf("%d", &tcCount);
    if(tcCount <= 0) {
        printf("Error! : invalid test case count.\n");
        return TCCERROR;
    }
    // 1-2. 테스트 케이스를 저장하는 포인터 배열공간 동적할당, 학생 수를 저장하는 정수형 배열 동적할당, 평균을 저장하는 배열 동적할당
    testCase = (int**)malloc(sizeof(int*)*tcCount);
    stdCount = (int*)malloc(sizeof(int)*tcCount);
    ave = (double*)malloc(sizeof(double)*tcCount);
    // 1-3. 각 테스트 케이스 별 학생 수 입력 + 예외처리
    for(int i=0 ; i<tcCount ; i++) {
        scanf("%d", stdCount+i); // 학생 수를 입력
        if((*(stdCount+i)<0) || (*(stdCount+i)>1000)) {
            printf("Error! : invalid student count.\n");
            return SCERROR;
        }
        // 1-4. 점수를 저장하기 위한 정수형 배열공간 동적할당
        *(testCase+i) = (int*)malloc(sizeof(int) * *(stdCount+i));
        // 1-5. 점수를 입력 + 예외처리
        for(int j=0 ; j<*(stdCount+i) ; j++) {
            scanf("%d", *(testCase+i)+j);
            if((*(*(testCase+i)+j) < 0) || (*(*(testCase+i)+j) > 100)) {
                printf("Error! : invalid score value range.\n");
                return SCOREERROR;
            }
        }
    }

    // 2. 평균을 계산하는 부분
    for(int i=0 ; i<tcCount ; i++) {
        // 2-1. 테스트 케이스에 입력된 점수의 총합을 계산
        for(int j=0 ; j<*(stdCount+i) ; j++)
            sum += *(*(testCase+i)+j);
        // 2-2. 총합을 학생 수로 나눠 평균을 계산 및 저장
        *(ave+i) = (double)sum / *(stdCount+i);
        sum = 0; // 해당 값의 재사용을 위해 sum 값을 0으로 초기화
    }

    // 3. 평균을 넘는 비율을 계산하여 출력하는 부분
    for(int i=0 ; i<tcCount ; i++) {
        // 3-1. 각 점수와 평균값을 비교 - 평균보다 큰 경우 카운트
        for(int j=0 ; j<*(stdCount+i) ; j++) {
            // 3-2. 평균보다 큰 점수만 1 카운트
            if(*(ave+i) < *(*(testCase+i)+j))
                upperCount++;
        }
        // 3-3. 평균보다 높은 점수의 비율을 계산 및 출력
        ratio = (double)upperCount / *(stdCount+i);
        printf("%.3f%%\n", ratio*100);
        upperCount = 0; // 다음 회차에 값을 재사용하기 위해 upperCount값 초기화
    }

    // 4. 동적할당한 메모리 공간을 해제 및 프로그램 종료
    for(int i=0 ; i<tcCount ; i++)
        free(*(testCase+i));
    free(testCase);
    free(stdCount);
    free(ave);
    return 0;
}