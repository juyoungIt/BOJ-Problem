/*
 * Q.2869 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int daytime;     // climbing height
    int night;       // sliding height
    int height;      // height of bar
    int remain;      // rest time
    int day = 0;     // climbing day

    scanf("%d %d %d", &daytime, &night, &height);
    day = (height - daytime) / (daytime - night);
    remain = (height - daytime) % (daytime - night);
    day++;
    if(remain != 0)
        day++;
    printf("%d\n", day);
    return 0;
}