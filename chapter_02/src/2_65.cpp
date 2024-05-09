#include <stdio.h>

int odd_ones(unsigned x)
{
    size_t size = sizeof(unsigned) << 3;
    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (x & 0x01)
        {
            sum++;
        }
        x = x >> 1;
    }
    return sum & 0x01;
}

int main(void)
{
    printf("%d true, %d false\n", odd_ones(0x01), odd_ones(0x03));
    return 0;
}
