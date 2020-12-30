#include <stdio.h>

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    if(num1 > num2)
        printf(">\n");
    else if(num1 < num2)
        printf("<\n");
    else
        printf("==");
    
    return 0;
}