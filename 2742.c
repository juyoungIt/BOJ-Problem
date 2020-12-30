#include <stdio.h>

int main() {
    int number; // 사용자 입력 수
    
    scanf("%d", &number);
    // 입력된 수에 대한 유효성 검사
    if(number < 1 || number > 100000) {
        printf("Error! - Invalid input value range.\n");
        return -1;
    }
    // 사용자 입력 수를 역순으로 출력
    for(int i=number ; i>0 ; i--) {
        printf("%d\n", i);
    }
    
    return 0;
}