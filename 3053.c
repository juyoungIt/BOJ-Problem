/*
 * Q.3053 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int r;
    double scale1, scale2;

    scanf("%d", &r);
    scale1 = r * r * M_PI;
    scale2 = r * r * 2;

    printf("%.6f\n", scale1);
    printf("%.6f\n", scale2);
    return 0;
}