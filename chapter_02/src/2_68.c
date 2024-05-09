#include <stdio.h>

unsigned mask1(int n)
{
    unsigned x = ~0;
    size_t w = sizeof(unsigned) << 3;
    x = x >> (w - n);
    return x;
}

int mask2(int n)
{
    int w = sizeof(int) << 3;
    if (n == w)
    {
        return ~0;
    }
    int mask = (1 << n) - 1;
    return mask;
}

int main(void)
{
    printf("number mask: %d, mask: %.2x, res: %d\n", 5, mask1(5), 0x1F ^ mask1(5));
    printf("number mask: %d, mask: %.2x, res: %d\n", 32, mask1(32), 0xFFFFFFFF ^ mask1(32));
    printf("number mask: %d, mask: %.2x, res: %d\n", 32, mask2(32), 0xFFFFFFFF ^ mask2(32));
    return 0;
}
