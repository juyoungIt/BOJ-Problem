/*
 * Q.2581 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>

int main()
{
    int m, n;           // the input number
    int primeSum = 0;   // the total sum of prime number between M ~ N
    int primeCount = 0; // the number of prime number between M ~ N
    int minPrime;       // the minimum value between valid prime number
    int i, j;           // the loop variable

    scanf("%d", &m);
    scanf("%d", &n);

    for(i=m ; i<=n ; i++) {
        for(j=1 ; j<=i ; j++) {
            if(i%j == 0 && (j!=1 && j!=i))
                break;
        }
        if(i != 1 && j == i+1) {
            primeSum += i;
            primeCount++;
            if(primeCount == 1)
                minPrime = i;
        }
    }
    if(primeCount == 0)
        printf("%d\n", -1);
    else {
        printf("%d\n", primeSum);
        printf("%d\n", minPrime);
    }
    return 0;
}