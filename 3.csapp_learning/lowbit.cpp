//
// Created by yu on 2024/3/25.
//
#include "stdlib.h"
#include "stdio.h"  
#include <string.h>
/*
 * x的二进制表达式中最低位的1所对应的值。
 * */
unsigned LowBit(unsigned x){
    unsigned a = x &((~x) + 1);
    return a;
}



/*
 * draw karnaugh map and get sum of product expression
 * IsLetter expression is f(x) = x3*(x1+x2)
 */
unsigned IsLetter(unsigned x){
    unsigned x1 = x & 0x22222222;
    unsigned x2 = x & 0x44444444;
    unsigned x3 = x & 0x88888888;
    return (x3 >> 3) &((x2 >> 2) |(x1 >> 1));
}

int main(){
    // segment array
    unsigned n = 7;
    printf("S[%u] = \n", n);
    printf("  T[%u]\n",n);
    n = n - LowBit(n);
    printf("+ T[%u]\n",n);
    n = n - LowBit(n);
    printf("+ T[%u]\n",n);
    n = n - LowBit(n);
    printf("+ T[%u]\n",n);

    printf("0x%x,is letter 0x%x\n",0xaaaaaaaa,IsLetter(0xaaaaaaaa));
    printf("0x%x,is letter 0x%x\n",0x11111111,IsLetter(0x11111111));


// uint64_t a = 0x12340000
// uint64_t b = 0xabcd                                   
    return 0;
}
