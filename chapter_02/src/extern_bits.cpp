#include "../include/converter.h"

int main(void)
{
    short sx = -12;
    unsigned short usx = sx;
    int x = sx;
    unsigned int ux = usx;

    printf("sx = %d\n", sx);
    show_bytes((bytes_pointer)&sx, sizeof(sx));
    printf("usx = %u\n", usx);
    show_bytes((bytes_pointer)&usx, sizeof(usx));
    printf("x = %d\n", x);
    show_bytes((bytes_pointer)&x, sizeof(x));
    printf("ux = %u\n", ux);
    show_bytes((bytes_pointer)&ux, sizeof(ux));

    return 0;
}