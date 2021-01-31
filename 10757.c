/*
 * Q.10757 Solution Source Code
 * Writer : JuyoungIt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num1[10000+2]; // the first input number (A)
    char num2[10000+2]; // the second input number (B)
    char* a;            // the reverse version of input number (A)
    char* b;            // the reverse version of input number (B)
    char* result;       // the result of add operation
    int len1;           // the length of string A
    int len2;           // the length of string B
    int len;            // the most longer length of string
    int carry = 0;      // the carry of each operation
    int tmp;

    scanf("%s %s", num1, num2);
    len1 = (int)strlen(num1);
    len2 = (int)strlen(num2);

    // memory allocation
    if(len1 > len2) {
        result = (char*)malloc(sizeof(char) * (len1+1));
        len = len1;
    }
    else {
        result = (char*)malloc(sizeof(char) * (len2+1));
        len = len2;
    }
    a = (char*)malloc(sizeof(char) * len);
    b = (char*)malloc(sizeof(char) * len);
    for(int i=0 ; i<len ; i++) {
        a[i] = '0';
        b[i] = '0';
    }

    // make reverse string
    for(int i=0 ; i<len1 ; i++)
        a[len1-(i+1)] = num1[i];
    for(int i=0 ; i<len2 ; i++)
        b[len2-(i+1)] = num2[i];

    // execute add operation
    for(int i=0 ; i<len+1 ; i++) {
        if(i == len)
            tmp = carry;
        else {
            tmp = (a[i]-48) + (b[i]-48) + carry;
            if(tmp >= 10) {
                tmp -= 10;
                carry = 1;
            }
            else
                carry = 0;
        }
        result[i] = (char)tmp;
    }

    // print the add operation result
    if(carry == 1)
        len++;
    for(int i=0 ; i<len ; i++)
        printf("%d", result[len-(i+1)]);
    printf("\n");

    // free memory space
    free(a);
    free(b);
    free(result);

    return 0;
}