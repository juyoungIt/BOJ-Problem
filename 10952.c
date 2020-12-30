#include <stdio.h>

int main() {
    int a, b;
    
    // 무한루프
    while(1) {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0)
            break; // 0 두 개가 입력되는 경우 - break
        if((a<1 || a>9)&&(b<1 || b>9))
            continue;
        printf("%d\n", a+b);
    }
    return 0;
}