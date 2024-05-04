#include <stdio.h>
#include "debug.h"

int main()
{
    unsigned x;
    //A
    x = ~0;
    printf("A: should be true: %d\n", !(~x));
    x = 0xFA;
    printf("A: should be false: %d\n", !(~x));

    //B
    x = 0x01;
    printf("B: should be false: %d\n", !x);

    //C
    x = 0x1234FF;
    printf("C: should be true: %d\n",  !(~(x | ~0xFF)));
    x = 0x123456;
    printf("C: should be false: %d\n", !(~(x | ~0xFF)));

    //D
    x = 0x123456;
    printf("D: should be true: %d\n", !(x >> ((sizeof(int) - 1) << 3)));
    x = 0xAB123456;
    printf("D: should be false: %d\n", !(x >> ((sizeof(int) - 1) << 3)));

    return 0;
}
