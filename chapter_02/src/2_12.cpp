#include <stdio.h>
#include "ltype.h"

int main(void)
{
    lint32 x = 0x87654321;
    printf("%8x\t%8x\n", 0x21, x & 0xFF);
    printf("%8x\t%8x\n", 0x789ABC21, x ^ ~0xFF);
    printf("%8x\t%8x\n", 0x876543ff, x | 0xFF);
    return 0;
}