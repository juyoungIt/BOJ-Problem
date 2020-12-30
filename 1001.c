#include <stdio.h>

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    if(num1 <= 0 && num2 >= 10)
        return 0;
    printf("%d\n", num1-num2);
    return 0;
}