#include <stdio.h>

int main() {
    int score; // 점수
    
    scanf("%d", &score); // 점수입력
    
    // 점수 값에 대한 예외처리
    if(score<0 || score>100)
        return -1; // 강제종료
    else if(score<=100 && score>=90)
        printf("A");
    else if(score<90 && score>=80)
        printf("B");
    else if(score<80 && score>=70)
        printf("C");
    else if(score<70 && score>=60)
        printf("D");
    else
        printf("F");
    
    return 0;
}