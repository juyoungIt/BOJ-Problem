#include <stdio.h>

int main() {
    
    int initial; // 사용자 입력 초기 정수값
    int sum; // 연산에 사용되는 합산 값
    int left, right; // 중간값을 생성하기 위한 첫째, 두번째 자리 수
    int new; // 연산을 통해 새롭게 생성된 수
    int middle; // 중간단계의 수
    int cycle = 0; // 사이클 수 저장
    
    // 사용자에게 정수 1개를 입력받음
    scanf("%d", &initial);
    middle = initial;
    
    // 사이클을 찾아내기 위한 loop로 진입
    while(1) {
        left = middle%10;
        sum = middle/10 + middle%10;
        right = sum%10;
        new = left*10 + right;
        cycle++; // 사이클 수 1증가
        if(initial == new)
            break;
        middle = new; // new를 새로운 중간값으로 할당
    }
    
    // 계산한 사이클 값을 출력
    printf("%d\n", cycle);
    return 0;
}