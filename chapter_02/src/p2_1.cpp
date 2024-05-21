#include <stdio.h>
#include <string>
#include <array>
#include "debug.h"

using namespace std;

std::string convert_integer(long val, int type);
std::array<char, 16> chars = { '0', '1', '2', '3',
                               '4', '5', '6', '7',
                               '8', '9', 'A', 'B',
                               'C', 'D', 'E', 'F' };

int main(void)
{
    printf("%s\n", convert_integer(0x9A78, 10).c_str());
    printf("%s\n", convert_integer(0x9A78, 16).c_str());
    printf("%s\n", convert_integer(0x9A78, 2).c_str());
    printf("%s\n", convert_integer(0x39A7F8, 16).c_str());
    return 0;
}

void swap_string(std::string& str)
{
    int size = str.size();
    for (int i = 0; i < size / 2; ++i)
    {
        int head = i;
        int tail = (size - 1) - i;
        if (head == tail)
        {
            continue;
        }
        char tmp = str[head];
        str[head] = str[tail];
        str[tail] = tmp;
    }
}

std::string convert_integer(long val, int type)
{
    std::string result;
    while (val > 0)
    {
        int index = (val % type);
        char c = chars[index];
        result.push_back(c);
        val = val / type;
    }
    swap_string(result);
    
    return result;
}
