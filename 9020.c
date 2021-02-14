/*
 * Q.9020 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tcSize; // the number of test case
    int* tc;    // store test case
    int p1, p2; // partition1 & 2
    int* pn;    // the list of prime number
    int pSize = 0;  // the number of prime number
    int size;

    scanf("%d", &tcSize);
    tc = (int*)malloc(sizeof(int) * tcSize);
    for(int i=0 ; i<tcSize ; i++)
        scanf("%d", &tc[i]);

    for(int i=0 ; i<tcSize ; i++) {
        // calculate prime number
        pn = (int*)malloc(sizeof(int) * (tc[i] + 1));
        for(int j=2 ; j<=tc[i] ; j++)
            pn[j] = j;
        for(int j=2 ; j<=tc[i] ; j++) {
            if(pn[j] == 0) continue;
            for(int k=j+j ; k<=tc[i] ; k+=j)
                pn[k] = 0;
        }
        // calculate the number of prime number
        for(int j=2 ; j<=tc[i] ; i++) {
            if(tc[j] != 0) pSize++;
        }
        size = (pSize%2 == 0) ? pSize/2 : pSize/2+1; // calculate search size
        /*
         * Search Algorithm here...
         */
    }

    free(tc);
    return 0;
}