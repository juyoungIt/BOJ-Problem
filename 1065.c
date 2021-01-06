/*
 * Q.1065 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#define INPUTERROR -1
#define TRUE 1
#define FALSE 0

// 함수 선언부
int hanNumCount(int n); // 1 ~ n 사이의 한수의 갯수를 구하여 반환
int isHanNum(int n); // 입력받은 수가 한수 인지 여부를 판별하여 결과값을 반환

int main()
{
    int n; // 1000보다 작거나 같은 자연수 N
    int result; // 결과값으로 구한 한수의 갯수
    // 1. 1000보다 작거나 같은 자연수 N 1개를 입력받음
    scanf("%d", &n);
    if((n<1) || (n>1000)) {
        printf("Error! : invalid input value range.\n");
        return INPUTERROR; // input error를 의미하는 -1을 반환하며 프로그램을 종료
    }
    // 2. 1보다 크거나 같고, N보다 작거나 같은 한수의 갯수를 구함
    result = hanNumCount(n);
    // 3. 한 수의 갯수를 출력함
    printf("%d\n", result);
    return 0;
}

// 함수 정의부
// 1 ~ n 사이의 한수의 갯수를 구하여 반환하는 함수
int hanNumCount(int n)
{
    int count = 0; // 존재하는 한수의 개수
    int result; // 해당 수가 한수 인지 여부에 대한 판별결과

    for(int i=1 ; i<=n ; i++) {
        result = isHanNum(i);
        if(result == TRUE)
            count++; // 찾은 한수의 갯수를 1증가
    }

    // 찾은 한수의 갯수값을 반환
    return count;
}

// 입력받은 수가 한수 인지 여부를 판별하여 결과값을 반환하는 함수
int isHanNum(int n)
{
    int temp = n;  // 계산을 위해서 사용하는 중간변수
    int num[4];    // 입력받은 수의 각 자릿수를 저장하는 배열
    int i=0;       // 반복문 변수
    int prev, cur; // 이전 자리수와 현재자리 수
    int diff;      // 각 자리수의 차를 계산하는 부분

    // 1. 인자로 받은 수의 각 자리수를 분해
    while(1) {
        if(temp == 0) break; // 모든 자리의 수를 계산한 경우 - 무한루프를 빠져나옴
        num[i] = temp%10; // 일의 자리 수를 추출하여 배열에 저장
        temp /= 10; // 다음번 일의 자리 수를 구하기 위하여 temp의 값을 갱신
        i++; // 다음 화차의 반복을 위해 i의 값을 1증가
    }

    // 2. 각 자리수의 차를 계산하여 비교
    for(int k=0 ; k<i-1 ; k++) {
        prev = num[k];
        cur = num[k+1];
        if(k == 0) diff = prev - cur; // 두 자리수의 차를 구함
        if((k > 0) && (diff != prev-cur)) return FALSE;
    }
    return TRUE;
}