#include <stdio.h>

int main() {
    int count; // 테스트 케이스의 수
    int num1, num2; // 사용자 입력 변수
    
    scanf("%d", &count); // 테스트 케이스의 수 입력
    
    for(int i=1 ; i<=count ; i++) {
        scanf("%d %d", &num1, &num2); // 2개의 정수 입력
        printf("%d\n", num1+num2); // 두 정수의 합산값을 출력
    }
    return 0;
}