#include <stdio.h>
#include "debug.h"

int fits_bits(int x, int n)
{
    int left = x & ~((1 << n) - 1);
    // int left = x & (~0 << n);
    DBGprint("shift1: %x, shift2: %x\n", ~((1 << n) - 1), ~0 << n);
    return !left || !(~left);
}

int main(void)
{
    printf("%d true, %d false\n", fits_bits(0x4F, 7), fits_bits(0x4F, 6));
    return 0;
}
