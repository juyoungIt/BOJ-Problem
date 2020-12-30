 #include <stdio.h>

int main() {
    int count; // 문제에서 명시하는 t값
    int a, b; // 입력받는 2개의 정수
    
    scanf("%d", &count); // t값 입력
    
    // count 값만큼 다음을 반복
    for(int i = 0 ; i<count ; i++) {
        scanf("%d %d", &a, &b);
        // 입력받는 2개의 정수에 대한 유효성 검사
        if((a<0 || a>10) || (b<0 || b>10)) {
            printf("Error! - invalid input value.\n");
            return -1;
        }
        printf("Case #%d: %d\n", i+1, a+b); // a, b의 합산결과를 출력
    }
    return 0;
}