#include <stdio.h>
#include <limits.h>
#include "debug.h"

int saturating_add(int x, int y)
{
    printf("input: x[%x],y[%x]\n", x, y);
    int sum32 = x + y;
    long sum64 = (long)x + (long)y;
    DBGprint("sum32: %d, %x\n", sum32, sum32);
    DBGprint("sum64: %ld, %lx\n", sum64, sum64);
    long positiveMask = 1 << ((sizeof(int) << 3) - 1);
    long negativeMask = positiveMask << 1;
    if (sum64 > 0 && (sum64 & positiveMask))
    {
        printf("positive overflow.\n");
        return INT_MAX;
    }
    else if (sum64 < 0 && (sum64 & negativeMask))
    {
        printf("negative overflow.\n");
        return INT_MIN;
    }
    return sum32;
}

int main(void)
{
    printf("Int_Max: %d, %x\n", INT_MAX, INT_MAX);
    printf("Int_Min: %d, %x\n", INT_MIN, INT_MIN);
    int positive = saturating_add(INT_MAX, 100);
    int negative = saturating_add(INT_MIN, -100);
    int normal = saturating_add(10, 10);
    printf("%d, %x\n", positive, positive);
    printf("%d, %x\n", negative, negative);
    printf("%d, %x\n", normal, normal);
    return 0;
}
