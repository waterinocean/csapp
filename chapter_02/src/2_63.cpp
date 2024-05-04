#include <stdio.h>
#include <list>
#include "debug.h"

using namespace std;

void show_bits(char byte);

typedef char* byte_pointer;
void show_bytes_in_little(byte_pointer byte_start, size_t len);

unsigned arl(unsigned x, int k)
{
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    unsigned mask = (~0) << ((sizeof(int) << 3) - k);
    mask = ~mask;
    xsra = xsra & mask;
    return xsra;
}

int lra(int x, int k)
{
    /* Perform shift logically */
    int xsr = arl(x, k);
    unsigned mask = (~0) << ((sizeof(int) << 3) - k);
    xsr = xsr | mask;
    return xsr;
}

int main(void)
{
    int x = 0xFF123456;
    printf("before shift:\n");
    show_bytes_in_little((byte_pointer)&x, sizeof(int));
    
    unsigned l = arl(x, 4);
    printf("after logic shift:\n");
    show_bytes_in_little((byte_pointer)&l, sizeof(unsigned));

    int a = lra(x, 4);
    printf("after arithmetic shift:\n");
    show_bytes_in_little((byte_pointer)&a, sizeof(int));

    return 0;
}

void show_bits(char byte)
{
    unsigned char val = byte;
    list<int> bits;
    while (val != 0)
    {
        int tmp = val % 2;
        bits.push_front(tmp);
        val = val / 2;
    }
    size_t zero_num = 8 - bits.size();
    for (size_t i = 0; i < zero_num; i++)
    {
        bits.push_front(0);
    }
    DBGprint("bits size: %d\n", bits.size());
    for (int bit: bits)
    {
        printf("%d", bit);
    }    
    printf("\n");
}

void show_bytes_in_little(byte_pointer byte_start, size_t len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        show_bits(byte_start[i]);
    }
}