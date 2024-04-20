#include <limits.h>
#include <stdio.h>

int main()
{
    printf("int max: %d\n int min: %d\n unsigned max: %u\n", INT_MAX, INT_MIN, UINT_MAX);    

    short int v = -12345;
    unsigned short int uv = (unsigned)v;
    printf("int:%d, unsigned:%u\n", v, uv);
    return 0;
}