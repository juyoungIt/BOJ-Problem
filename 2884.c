#include <stdio.h>

int main() {
    int hour, minute; // 사용자 입력 시간/분
    int r_hour, r_minute; // 적용결과 시간/분
    
    // 시간 입력 및 예외처리
    scanf("%d %d", &hour, &minute);
    // 시간
    if(0>hour || 23<hour)
        return -1;
    if(0>minute || 59<minute)
        return -1;
    
    // 입력시간 변환
    r_minute = minute - 45; // 45분 차감
    if(r_minute < 0) {
        r_hour = hour - 1; // 시간 자리가 바뀌어야 하는 경우
        if(r_hour<0)
            r_hour = 23;
        r_minute += 60; // 시간 자리가 바뀌어야 하는 경우
    }
    else
        r_hour = hour; // 시간 자리가 바뀌지 않아도 되는 경우
    
    // 결과 출력
    printf("%d %d\n", r_hour, r_minute);
    return 0;
}