#include "../include/show_bytes.h"
#include "../include/debug.h"
#include <time.h>


void assignTo(long long val, char array[8])
{
    for (int i = 7; i >= 0; i--)
    {
        char tmp = val & 0xFF;
        DBGprint("array[%d]: %d", i, tmp);
        array[i] = tmp;
        val = val >> 8;
    }
    show_bytes((bytes_pointer)array, 8);        
}

long long getValueFrom(char array[8])
{
    long long result = 0;
    for (size_t i = 0; i < 8; i++)
    {
        DBGprint("array[%d]: %d", i, array[i]);
        result = result | array[i];
        DBGprint("result before: %x", result);
        result = result << 8;
        DBGprint("result after: %x", result);
    }
    show_bytes((bytes_pointer)&result, 8);
    return result;
}

int main()
{
    long long now = time(NULL);
    DBGprint("now is: %x", now);
    show_bytes((bytes_pointer)&now, sizeof(long long));
    char array[8] = "";
    assignTo(now, array);
    long long val = getValueFrom(array);
    return 0;
}
