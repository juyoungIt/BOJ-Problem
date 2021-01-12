/*
 * Q.2908 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define INPUTERROR -1

// 함수 선언부
int inputCheck(int num1, int num2); // 입력으로 들어온 두 수의 제약조건 검사
int readRev(int before); // 입력으로 들어온 두 수를 거꾸로 읽은 값을 반환

int main()
{
    int beforeA, beforeB; // 입력받는 0을 포함하지 않는 3자리의 자연수
    int afterA, afterB; // 입력받은 수를 뒤집은 결과

    // 1. 2개의 세자리 수 입력 (+ 예외처리)
    scanf("%d %d", &beforeA, &beforeB);
    if(inputCheck(beforeA, beforeB) == FALSE) {
        printf("Error! - invalid input value.\n");
        return INPUTERROR;
    }

    // 2. 거꾸로 읽은 수를 생성
    afterA = readRev(beforeA);
    afterB = readRev(beforeB);

    // 3. 생성한 수 중에서 더 큰 수를 판별하여 출력
    if(afterA > afterB)
        printf("%d\n", afterA);
    else
        printf("%d\n", afterB);
    return 0;
}

// 함수 정의부
int inputCheck(int num1, int num2) {
    int tmp1 = num1; // 계산과정 중간값 임시저장 - 1
    int tmp2 = num2; // 계산과정 중간값 임시저장 - 2

    // 1. 입력된 두 수가 세자리 수 인지 확인
    if((num1<100 || num1>=1000) || (num2<100 || num2>=1000))
        return FALSE;
    // 2. 입력된 두 수가 0을 자릿수에 0을 포함하는 지 확인
    for(int i=0 ; i<3 ; i++) {
        if(tmp1%10 == 0 || tmp2%10 == 0) return FALSE;
        tmp1 /= 10;
        tmp2 /= 10;
    }
    // 3. 입력된 두 수가 서로 같은 값인지 확인
    if(num1 == num2)
        return FALSE;
    return TRUE;
}

int readRev(int before)
{
    int result = 0; // 입력된 수를 거꾸로 읽은 결과
    int tmp = before; // 연산과정의 중간값을 임시저장

    for(int i=0 ; i<3 ; i++) {
        result += tmp%10 * (int)pow(10, 2-i);
        tmp/=10;
    }
    return result;
}