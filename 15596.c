/*
 * Q.15596 Solution Source Code
 * Writer : JuyoungIt
 */

/*
 * 조금 특이한 케이스의 문제로서 전체 코드를 작성하는 것이 아닌 함수 부분에 대한 코드 작성만으로 평가를 진행하는 부분임.
 */

long long sum(int *a, int n) {
    long long ans = 0;
    for(int i=0 ; i<n ; i++) {
        ans += *(a+i);
    }
    return ans;
}