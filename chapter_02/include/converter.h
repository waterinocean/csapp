#ifndef CONVERTER_H
#define CONVERTER_H

#include "debug.h"
#include <stdio.h>
#include <string>
#include <list>
#include <iostream>
#include <array>
#include <map>
#include <algorithm>


typedef char* bytes_pointer;
void show_bytes(bytes_pointer start, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        printf("%2.2x, 0x%u\t", start[i], &start[i]);
    }
    printf("\n");
}

std::string toString(unsigned long long val, unsigned int type = 10)
{
    static std::map<unsigned int, std::string> mapSupported = {{2, "0b"}, {8, "0"}, {10, ""}, {16, "0x"}};
    static std::array<char, 16> chars = {'0', '1', '2', '3', 
                                       '4', '5', '6', '7',
                                       '8', '9', 'A', 'B',
                                       'C', 'D', 'E', 'F'};
    std::map<unsigned int, std::string>::iterator it = mapSupported.find(type);
    if (it == mapSupported.end())
    {
        std::cout << "unsupported type" << std::endl;
        return "";
    }
    std::string prefix = (*it).second;
    DBGprint("prefix: %s\n", prefix.c_str());
    std::string temp, result;
    //compute
    while (val > 0)
    {
        char c = chars[val % type];
        temp.push_back(c);
        val /= type;
    }
    DBGprint("string size is: %ld\n", temp.size());
    //compose string
    result += prefix;
    DBGprint("result: %s, prefix: %s\n", result.c_str(), prefix.c_str());
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        DBGprint("i: %d\n", i);
        result.push_back(temp.at(i));
    }
    return result;
}

#endif
