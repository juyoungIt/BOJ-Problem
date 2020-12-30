#include <stdio.h>

int main() {
    int sequence[10000]; // 수열을 저장하는 배열선언
    int n, x; // 문제에서 언급한 n, x 값을 저장하는 변수
    scanf("%d %d\n", &n, &x); // 문제에서 언급한 n, x값을 입력받음
    
    // 입력된 수들에 대한 유효성 검사
    if((n<1 || n>10000) || (x<1 || x>10000)) {
        printf("Error! - invalid input value range!.");
        return -1;
    }
    
    // 문제에서 탐색의 대상이 되는 수열 입력
    for(int i=0 ; i<n ; i++) {
        scanf("%d", &sequence[i]);
    }
    
    //  입력된 수열을 바탕으로 유효한 값 탐색진행
    for(int i=0 ; i<n ; i++) {
        if(sequence[i] < x)
            printf("%d ", sequence[i]);
    }
    return 0;
}