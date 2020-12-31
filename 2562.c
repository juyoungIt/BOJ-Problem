/*
Q. 2562 Solution Source Code
Writer : JuyoungIt
*/

#include <stdio.h>

int main()
{
    int arr[9]; // 사용자 입력변수를 저장
    int max = -1; // 최대값
    int idx; // 최대값의 배열상 인덱스

    // 사용자로부터 서로 다른 9개의 정수를 순서대로 입력받음
    for(int i=0 ; i<9 ; i++)
    {
        scanf("%d", &arr[i]);
        // 입력 변수 값의 범위에 대한 예외처리
        if((arr[i] < 1) || (arr[i] > 100))
        {
            printf("Error! : invalid input error!\n");
            return -1; // 입력값의 범위 오류를 의미하는 -1을 반환하며 프로그램 종료
        }
    }

    // 입력한 9개의 자연수 중에서 최댓값과 그 인덱스를 찾음
    for(int i=0 ; i<9 ; i++)
    {
        if(max < arr[i])
        {
            max = arr[i]; // 최댓값을 업데이트
            idx = i+1; // 최댓값의 인덱스를 업데이트
        }
    }

    // 구한 최댓값과 그 인덱스를 출력
    printf("%d\n", max);
    printf("%d\n", idx);
    return 0;
}