#include <stdio.h>
#include "debug.h"

int leftmost_one(unsigned x)
{
    DBGprint("input: %.2x\n", x);
    size_t size = sizeof(unsigned) << 3;
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += (x & 0x01);
        x = x >> 1;
    }
    DBGprint("before shift, sum: %d\n", sum);
    sum = sum << ((size - 1) << 3);
    DBGprint("after shift, sum: %d\n", sum);    
    return sum;
}

int main(void)
{
    int x = 0xff00;
    printf("%.2x %.2x\n", x, leftmost_one(x));
    return 0;
}
