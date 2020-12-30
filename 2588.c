#include <stdio.h>

int main()
{
    int num1, num2;
    int middle=0;
    int result1, result2, result3, result4;

    scanf("%d %d", &num1, &num2);

    result1 = num1 * (num2 % 10);
    
    middle = num2 % 100;
    if (middle % 10 != 0) {
        middle = middle / 10;
        result2 = num1 * middle;
    }
    else
        result2 = num1 * middle/10;
    
    result3 = num1 * (num2/100);
    result4 = num1 * num2;

    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);
    return 0;
}