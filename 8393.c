#include <stdio.h>

int main() {
    int number; // 사용자 입력 수
    int sum = 0; // 합산 값
    
    scanf("%d", &number);
    
    if(number < 1 || number > 10000) {
        printf("input range error!\n");
        return -1;
    }
    
    for(int i=1 ; i<=number ; i++) {
        sum += i;
    }
    
    printf("%d", sum);
    return 0;
}