
#include <stdio.h>
#include <string.h>

typedef char* bytes_pointer;
void show_bytes(bytes_pointer ptr, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        printf("%.2x ", ptr[i]);
    }
    printf("\n");
}

void show_int(int val, size_t len)
{
    show_bytes((bytes_pointer)&val, len);
}

void show_double(double val, size_t len)
{
    show_bytes((bytes_pointer)&val, len);
}

int main()
{
    const char* s = "abcdef";
    show_bytes((bytes_pointer)s, strlen(s));
    return 0;
}
