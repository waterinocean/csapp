#ifndef SHOW_BYTES_H
#define SHOW_BYTES_H

#include <stdio.h>
#include <iostream>
#include "debug.h"

// typedef char* bytes_pointer;
typedef uint8_t* bytes_pointer;
void show_bytes(bytes_pointer ptr, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        DBGprint("%d ", ptr[i]);
        printf("0x%.2x ", ptr[i]);
    }
    printf("\n");
}

bool is_littel_endian(void)
{
    int testNum = 0xff;
    bytes_pointer byteStart =  bytes_pointer(&testNum);
    show_bytes(byteStart, sizeof(int));
    if (byteStart[0] == 0xff)
    {
        return 1;
    }
    return 0;
}

#endif
