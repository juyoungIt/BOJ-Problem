#include <stdio.h>

int main() {
    int num1, num2;
    double result;
    
    scanf("%d %d", &num1, &num2);
    
    result = (double)num1 / num2;
    
    printf("%.9lf\n", result);
    return 0;
}