#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // 입력받을 정수의 개수
    int min = 1000000; // 최소값
    int max = -1000000; // 최대값
    int* arr; // 정수의 배열을 가리키는 부분

    // 사용자로부터 정수의 개수를 입력받는 부분
    scanf("%d", &n);

    // 입력된 값의 범위에 대한 예외처리
    if((n<1) || (n>1000000))
    {
        printf("Error! : invalid input value range!\n");
        return -1; // 정수의 개수값 입력에서 오류가 발생했음을 의미하는 -1을 반환하며 종료
    }

    // 정수를 입력받을 배열을 생성하는 부분 - 입력받은 길이 만큼의 정수형배열의 공간을 할당함.
    arr = (int*)malloc(sizeof(int) * n);

    // 원하는 수 만큼의 정수를 입력받는 부분
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d", arr+i);
        // 입력된 값의 범위에 대한 예외처리
        if((*(arr+i) < -1000000) || (*(arr+i) > 1000000))
        {
            printf("Error! : invalid input value range!\n");
            return -2; // 정수 입력과정에서 오류가 발생했음을 의미하는 -2를 반환하며 종료
        }
    }

    // 입력받은 정수 중에서 최소값과 최대값을 선정하여 구함
    for(int i=0 ; i<n ; i++)
    {
        if(*(arr+i) < min)
            min = *(arr+i);
        if(*(arr+i) > max)
            max = *(arr+i);
    }

    // 결과값을 출력함
    printf("%d %d\n", min, max);

    // 동적으로 할당한 메모리 공간을 반납후 프로그램 종료
    free(arr);
    return 0;
}