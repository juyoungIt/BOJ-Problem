#include <stdio.h>

int main() {
    int num; // 사용자 입력 수
    int i; // 반복문 변수
    
    scanf("%d", &num);
    
    for(i=0 ; i<9 ; i++)
        printf("%d * %d = %d\n", num, i+1, num * (i+1));
    
    return 0;
}