#include <stdio.h>

void replace_byte(unsigned x, int index, unsigned char b)
{
    printf("input: 0x%.2x %d %.2x\n", x, index, b);
    unsigned mask1 = 0xFF;
    unsigned mask2 = b;
    for (size_t i = 0; i < index; i++)
    {
        mask1 = mask1 << 8;
        mask2 = mask2 << 8;
    }
    printf("mask-1: %.2x\n", mask1);
    mask1 = ~mask1;
    printf("mask-2: %.2x\n", mask1);
    x = x & mask1;
    printf("x: %.2x\n", x);
    x = x | mask2;
    printf("output: 0x%.2x\n\n", x);
}

void replace_byte_v2(unsigned x, int index, unsigned char b)
{
    printf("input: 0x%.2x %d %.2x\n", x, index, b);
    char* p = (char *)&x;
    p[index] = b;
    printf("output: 0x%.2x\n\n", x);
}

int main()
{
    unsigned x = 0x12345678;
    unsigned char b = 0xAB;
    replace_byte(x, 2, b);
    replace_byte(x, 0, b);

    replace_byte_v2(x, 2, b);
    replace_byte_v2(x, 0, b);
    return 0;
}
