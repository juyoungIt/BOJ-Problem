/*
 * Q.9020 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>

int isPrime(int* list, int n, int size);

int main()
{
    int tcSize;      // the number of test case
    int* tc;         // store test case
    int p1, p2;      // partition1 & 2
    int* pn;         // the list of prime number
    int* pList=NULL; // the list of prime number(except zero)
    int pSize = 0;   // the number of prime number
    int size;        // the size of search

    scanf("%d", &tcSize);
    tc = (int*)malloc(sizeof(int) * tcSize);
    for(int i=0 ; i<tcSize ; i++)
        scanf("%d", &tc[i]);

    for(int i=0 ; i<tcSize ; i++) {
        pn = (int*)malloc(sizeof(int) * (tc[i] + 1));
        for(int j=2 ; j<=tc[i] ; j++)
            pn[j] = j;
        for(int j=2 ; j<=tc[i] ; j++) {
            if(pn[j] == 0) continue;
            for(int k=j+j ; k<=tc[i] ; k+=j)
                pn[k] = 0;
        }
        for(int j=2 ; j<=tc[i] ; j++) {
            if(pn[j] != 0) {
                pList = (int*)realloc(pList, sizeof(int) * (pSize+1));
                pList[pSize] = pn[j];
                pSize++;
            }
        }
        size = (pSize%2 == 0) ? pSize/2 : pSize/2+1; // calculate search size
        for(int j=0 ; j<size ; j++) {
            if(isPrime(pList, tc[i]-pList[j], pSize) == 1) {
                p1 = pList[j];
                p2 = tc[i]-p1;
            }
        }
        printf("%d %d\n", p1, p2);
        free(pn);
        pSize = 0;
    }
    free(tc);
    return 0;
}

int isPrime(int* pList, int num, int pSize)
{
    for(int i=0 ; i<pSize ; i++) {
        if(pList[i] == num) return 1;
    }
    return 0;
}