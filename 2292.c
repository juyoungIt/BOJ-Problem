/*
 * Q.2292 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int num; // user input number
    int levelMax; // the maximum value of each level
    int level; // the level of input (0 ~)

    scanf("%d", &num);
    level = 0;
    while(1) {
        levelMax = level * (3 * level + 3) + 1;
        if(levelMax >= num)
            break;
        else
            level++;
    }
    printf("%d\n", level+1);
    return 0;
}