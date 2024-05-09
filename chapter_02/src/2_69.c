#include <stdio.h>
#include "debug.h"

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(unsigned) << 3;
    DBGprint("w: %d\n", w);
    unsigned mask1 = x >> (w - n);
    unsigned mask2 = x << n;
    DBGprint("mask1: %.2x, mask2: %.2x\n", mask1, mask2);

    return mask1 | mask2;
}

int main(void)
{
    int x = 0x12345678;
    printf("%.2x %.2x\n", x, rotate_left(x, 4));
    printf("%.2x %.2x\n", x, rotate_left(x, 20));
    return 0;
}