#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

#include <stdio.h>
#include "debug.h"

typedef char* bytes_pointer;
void show_bytes(bytes_pointer ptr, size_t len)
{
    DBGprint("ptr: 0x%.2x, len: %u", ptr, len);
    for (size_t i = 0; i < len; ++i)
    {
        DBGprint("the %d byte is %d", i, ptr[i]);
        printf("%x \n", ptr[i]);
    }
    printf("\n");
}

#endif
