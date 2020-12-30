#include <stdio.h>

int main() {
    int n; // 화면에 출력할 별의 수 (사용자 입력)

    // 사용자로부터 출력할 별의 수를 입력받는 부분
    scanf("%d", &n);

    // 입력되는 값의 범위에 대한 예외처리
    if((n < 1) || (n > 100))
    {
        printf("Error! : invalid input value range\n");
        return -1; // 오류를 의미하는 -1을 반환
    }

    // 입력받은 값을 바탕으로 별을 그려내는 부분
    // 1. 라인에 대한 부분
    for(int i=1 ; i<n+1 ; i++)
    {
        // 2. 빈공간을 그려내는 부분
        for(int j=0 ; j<n-i ; j++)
            printf(" ");
        // 3. 별을 그려내는 부분
        for(int k=1 ; k<i+1 ; k++)
            printf("*");
        // 4. 다음 라인을 위한 개행
        printf("\n");
    }
    return 0;
}
