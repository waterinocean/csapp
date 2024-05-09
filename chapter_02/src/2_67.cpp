#include <stdio.h>
#include "debug.h"

int int_size_is_32(void)
{
   int set_msb = 1 << 31;
   int beyond_msb = set_msb << 1;
   DBGprint("set msb:%d, beyond msb:%d\n", set_msb, beyond_msb);
   return set_msb && !beyond_msb;
}

int main(void)
{
    printf("is 32 bits: %d\n", int_size_is_32());
    return 0;
}