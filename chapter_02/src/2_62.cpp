#include <stdio.h>

bool int_shifts_are_arithmetic(void)
{
    int x = 1;
    x = x << ((sizeof(int) << 3) - 1);
    printf("before >>, hex is: 0x%.8x\n", x);
    x = x >> ((sizeof(int)) << 3);
    printf("after >>, hex is: 0x%x\n", x);
    return x;
}

int main()
{
    printf("int shifts are arithmetic: %d\n", int_shifts_are_arithmetic());
    return 0;
}
