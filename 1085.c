/*
 * Q.1085 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int x, y; // the current coordinate (x, y)
    int w, h; // the right top of rectangle (w, h)
    int dist[4];
    int minDist;

    scanf("%d %d %d %d", &x, &y, &w, &h);
    dist[0] = h-y;
    dist[1] = x;
    dist[2] = y;
    dist[3] = w-x;

    minDist = dist[0];
    for(int i=0 ; i<4 ; i++) {
        if(dist[i] < minDist)
            minDist = dist[i];
    }
    printf("%d\n", minDist);
    return 0;
}