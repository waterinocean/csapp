#include <stdio.h>
#include <limits.h>
#include "debug.h"

int tsub_ok(int x, int y)
{
    printf("input: x[%x],y[%x]\n", x, y);
    int sum32 = x - y;
    long sum64 = (long)x - (long)y;
    DBGprint("sum32: %d, %x\n", sum32, sum32);
    DBGprint("sum64: %ld, %lx\n", sum64, sum64);
    long positiveMask = 1 << ((sizeof(int) << 3) - 1);
    long negativeMask = positiveMask << 1;
    if (sum64 > 0 && (sum64 & positiveMask))
    {
        printf("positive overflow.\n");
        return 0;
    }
    else if (sum64 < 0 && (sum64 & negativeMask))
    {
        printf("negative overflow.\n");
        return 0;
    }
    return 1;
}

int main(void)
{
    printf("%d, %d\n", tsub_ok(INT_MAX, INT_MAX), tsub_ok(INT_MAX, INT_MIN));
    return 0;
}
