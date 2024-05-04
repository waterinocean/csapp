#include "show_bytes.h"

typedef int64_t WORD;
void f(WORD x, WORD y)
{
    printf("input x: \n");
    show_bytes(bytes_pointer(&x), sizeof(WORD));
    printf("input y: \n");
    show_bytes(bytes_pointer(&y), sizeof(WORD));
    WORD result = (x & 0xFF) | (y & ~0xFF);
    printf("output: \n");
    show_bytes(bytes_pointer(&result), sizeof(WORD));
}

int main()
{
    f(0x89ABCDEF, 0x87654321);
    return 0;
}
