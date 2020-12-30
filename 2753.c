#include <stdio.h>

int main() {
    int year; // 연도값
    int result = 0; // 윤년 여부
    
    scanf("%d", &year);
    
    if(year<=0 && year > 4000)
        return -1; // 연도값이 범위 초과
    
    if(year % 4 == 0) {
        result = 1;
        if(year % 100 == 0) {
            result = 0;
            if(year % 400 == 0)
                result = 1;
        }
    }
    
    printf("%d\n", result);
    return 0;
}