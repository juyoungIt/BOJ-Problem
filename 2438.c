#include <stdio.h>

int main() {
    int count; // 별을 출력할 라인 수
    scanf("%d", &count);
    
    // 입력된 값들에 대한 유효성 검사
    if(count < 1 || count > 100) {
        printf("Error! - invalid input value\n");
        return -1;
    }
    
    // 별을 출력
    for(int i=0 ; i<count ; i++) {
        for(int j=0 ; j<=i ; j++) {
            printf("*");
        }
        if(i != count-1)
            printf("\n");
    }
    return 0;
}