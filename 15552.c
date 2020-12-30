#include <stdio.h>

int main() {
    int t; // t값을 저장하는 변수 -> 최대 1000000
    int a, b;
    
    scanf("%d", &t); // t를 자동으로 입력받음
    // 입력받은 t값에 대한 예외처리
    if(t<1 || t>1000000) {
        printf("Error! - invalid T value range.\n");
        return -1;
    }
    
    for(int i=1 ; i<=t ; i++) {
        scanf("%d %d", &a, &b); // a와 b 값을 입력받음
        // a, b 값에 대한 예외처리
        if((a<1 || a>1000) || (b<1 || b>1000)) {
            printf("Error! input value range invalid.\n");
            return -2;
        }
        // a+b 값을 출력
        printf("%d\n", a+b);
    }
    return 0;
}