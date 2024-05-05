#include <stdio.h>

int any_odd_one(unsigned x)
{
    return !(1 && ((x & 0x55555555) ^ 0x55555555));
}

int main(void)
{
    printf("0x%x is odd: %d\n", 0x54, any_odd_one(0x54));
    printf("0x%x is odd: %d\n", 0x55555555, any_odd_one(0x55555555));
    return 0;
}
