#include <iostream>
#include "../include/converter.h"

using namespace std;

void printUnsigned(unsigned long val);

int main()
{
    printUnsigned(35);
    printUnsigned(53);
    return 0;
}

void printUnsigned(unsigned long val)
{
    std::string decimal = toString(val, 10);
    std::string binary = toString(val, 2);
    std::string octal = toString(val, 8);
    std::string hex = toString(val, 16);
    printf("val: %ld, decimal: %s, binary: %s, octal; %s, hex: %s\n", 
            val, decimal.c_str(), binary.c_str(), octal.c_str(), hex.c_str());
}
