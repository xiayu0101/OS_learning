#include "stdio.h"

int main(){
    unsigned *p;
    p = (void *)main;
    printf("%x\n",*p);
}