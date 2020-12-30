#include <stdio.h>

int main() {
    int x, y; // x, y 좌표
    int quadrant; // 사분면
    
    scanf("%d", &x); // x좌표 입력받기
    scanf("%d", &y); // y좌표 입력받기
    
    // 입력 좌표에 대한 유효성 검사
    if(x < -1000 || x > 1000)
        return -1;
    if(y < -1000 || y > 1000)
        return -1;
    if(x == 0 || y == 0)
        return -1;
    
    // 사분면 판정
    if(x>0 && y>0)
        quadrant = 1;
    else if(x<0 && y>0)
        quadrant = 2;
    else if(x<0 && y<0)
        quadrant = 3;
    else if(x>0 && y<0)
        quadrant = 4;
    else
        return -1; // 발생할 가능성은 거의 없지만 오류가 발생한 경우에 대한 예외처리
    
    // 사분면 판정결과 출력
    printf("%d\n", quadrant);
    return 0;
}