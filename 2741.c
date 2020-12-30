#include <stdio.h>

int main() {
    int number; // 사용자 입력정수
    
    scanf("%d", &number);
    // 입력 정수에 대한 유효성 검사
    if(number < 1 || number > 100000) {
        printf("Error! - invalid input value range!\n");
        return -1;
    }
    
    // 한라인씩 수를 출력
    for(int i=1 ; i<=number ; i++) {
        printf("%d\n", i);
    }
    
    return 0;
}