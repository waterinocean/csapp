#include "show_bytes.h"

void show_number(int num);

int main()
{
    show_number(1);
    show_number(0x1234);
    printf("Little Endian: %d\n", is_littel_endian());
    return 0;
}

void show_number(int num)
{
    printf("input: %.2x\n", num);
    show_bytes((bytes_pointer)&num, sizeof(int));
}
