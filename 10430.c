#include <stdio.h>

int main()
{
    int num1, num2, num3;
    int result1, result2, result3, result4;
    
    scanf("%d %d %d", &num1, &num2, &num3);
    result1 = (num1 + num2) % num3;
    result2 = ((num1%num3) + (num2%num3))%num3;
    result3 = (num1 * num2) % num3;
    result4 = ((num1%num3) * (num2%num3))%num3;
    
    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);
    return 0;
}