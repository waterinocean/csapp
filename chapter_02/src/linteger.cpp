#include "../include/linteger.h"
#include <cmath>
#include <cstdlib>
#include "../include/debug.h"
#include "linteger.h"

std::map<char, int> LInteger::m_mapNum =  {   
                                                    {'0', 0},   {'1', 1},   {'2', 2},   {'3', 3},
                                                    {'4', 4},   {'5', 5},   {'6', 6},   {'7', 7},
                                                    {'8', 8},   {'9', 9},   {'A', 10},  {'B', 11},
                                                    {'C', 12},  {'D', 13},  {'E', 14},  {'F', 15}
                                                };
std::map<int, char> LInteger::m_mapStr =  {   
                                                    {0, '0'},   {1, '1'},   {2, '2'},   {3, '3'},
                                                    {4, '4'},   {5, '5'},   {6, '6'},   {7, '7'},
                                                    {8, '8'},   {9, '9'},   {10, 'A'},  {11, 'B'},
                                                    {12, 'C'},  {13, 'D'},  {14, 'E'},  {15, 'F'}
                                                };

LInteger::LInteger(const std::string& value, int base/*=10*/)
    : m_signed(false)
{
    DBGprint("constructor: value[%s], base[%d]\n", value.c_str(), base);
    init(value, base);
}

LInteger& LInteger::operator=(const LInteger &value)
{
    m_number = value.m_number;
    m_signed = value.m_signed;
    return *this;
}

LInteger::LInteger(const LInteger &value)
{
    m_number = value.m_number;
    m_signed = value.m_signed;
}

std::string LInteger::hex(void) const
{
    std::string result;
    size_t sizeHex = m_number.size() / 4;
    for (size_t i = 0; i < sizeHex; i++)
    {
        std::string hexStr;
        hexStr += m_number[4 * i];
        hexStr += m_number[4 * i + 1];
        hexStr += m_number[4 * i + 2];
        hexStr += m_number[4 * i + 3];
        int index = binaryToDecimal(hexStr.c_str(), 4);
        char hexC = m_mapStr[index];
        result += hexC;
    }
    
    return result;
}

std::string LInteger::binary(void) const
{
    return m_number;
}

long long LInteger::decimal(void)
{
    long long result = 0;
    std::string value = m_number;
    if (m_littleEndian)
    {
        swapByte(value);
    }
    result = binaryToDecimal(value.c_str(), value.size(), m_signed);
    return result;
}

LInteger &LInteger::operator&(const LInteger &right)
{
    return *this;
}

LInteger &LInteger::operator|(const LInteger &right)
{
    return *this;
}

LInteger &LInteger::operator~(void)
{
    return *this;
}

LInteger &LInteger::operator<<(size_t n)
{
    return *this;
}

LInteger &LInteger::rightShiftInLogic(size_t n)
{
    return *this;
}

LInteger &LInteger::rightShiftInArithMetic(size_t n)
{
    return *this;
}

LInteger LInteger::B2U(const LInteger &val)
{
    return LInteger("0");
}

LInteger LInteger::B2T(const LInteger &val)
{
    return LInteger("0");
}

LInteger LInteger::U2B(const LInteger &val)
{
    return LInteger("0");
}

LInteger LInteger::U2T(const LInteger &val)
{
    return LInteger("0");
}

LInteger LInteger::T2U(const LInteger &val)
{
    return LInteger("0");
}

LInteger LInteger::T2B(const LInteger &val)
{
    return LInteger("0");
}

bool LInteger::m_littleEndian = false;
void LInteger::setLittleEndian(bool littleEndian)
{
    m_littleEndian = littleEndian;
}

void LInteger::init(const std::string &value, int base)
{
    if (value.size() == 0)
    {
        return;
    }
    if (value[0] == '-')
    {
        m_signed = true;
    }
    unsigned long long number = toNumber(value, base);
    DBGprint("init: number[%llu]\n", number);
    m_number = toBinary(number);
    DBGprint("init: binary[%s]\n", m_number.c_str());
    fulfillByte(m_number, m_signed);
    DBGprint("init: after fulfill8[%s]\n", m_number.c_str());
    if (m_signed)
    {
        m_number[0] = '1';        
    }
    m_number = O2T(m_number);
    DBGprint("init: O2T[%s]\n", m_number.c_str());
    if (m_littleEndian)
    {
        swapByte(m_number);
        DBGprint("init: little endian[%s]\n", m_number.c_str());
    }
}

long long LInteger::pow(int base, int n) const
{
    long long result = 1;
    if (n == 0)
    {
        return 1;
    }
    return base * pow(base, n - 1);
}

unsigned long long LInteger::toNumber(const std::string &str, int base)
{
    unsigned long long result = 0;
    size_t size = str.size();
    for (int i = 0, place = size - 1; i < size; ++i, --place)
    {
        if (str[i] == '-')
        {
            continue;
        }
        result += m_mapNum[str[i]] * pow(base, place);
    }
    return result;
}

std::string LInteger::toBinary(unsigned long long number)
{
    std::string result;
    while (number > 0)
    {
        char c = m_mapStr[number % 2];
        result.push_back(c);
        number /= 2;
    }
    swapBit(result);
    return result;
}

void LInteger::swapBit(std::string &str)
{
    size_t size = str.size();
    for (int head = 0, tail = size - 1; head < tail; ++head, --tail)
    {
        swap(str, head, tail);
    }
}

void LInteger::swapByte(std::string &str)
{
    size_t sizeByte = str.size() / 8;
    if (sizeByte == 1)
    {
        return;
    }
    for (int head = 0, tail = sizeByte - 1; head < tail; ++head, --tail)
    {
        for (size_t i = 0; i < 8; ++i)
        {
            swap(str, 8 * head + i, 8 * tail + i);
        }
    }
}

void LInteger::swap(std::string &str, int i, int j)
{
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
}

void LInteger::fulfillByte(std::string &binary, bool isSigned)
{
    int numZero = 0;
    size_t size = binary.size();
    if (size % 8 == 0)
    {
        if (isSigned)
        {
            numZero = 8;
        }
    }
    else
    {
        numZero = 8 - (size % 8);
    }

    std::string fulfilled(numZero, '0');
    binary = fulfilled + binary;
}

std::string LInteger::O2T(const std::string& binary)
{
    std::string result = binary;
    if (result[0] == '0')
    {
        return result;
    }
    for (int i = 1; i < result.size(); ++i)
    {
        if (result[i] == '1')
        {
            result[i] = '0';
        }
        else
        {
            result[i] = '1';
        }
    }
    for (int i = result.size() - 1; i >= 1; --i)
    {
        if (result[i] == '0')
        {
            result[i] = '1';
            break;
        }
        result[i] = '0';
    }
    return result;
}

long long LInteger::binaryToDecimal(const char *byte, size_t size, bool isSigned/* = false*/) const
{
    long long result = 0;
    int sign = isSigned ? -1 : 1;
    for (size_t i = 0, place = size - 1; i < size; ++i, --place)
    {
        if (i == 0)
        {
            result += sign * m_mapNum[byte[i]] * pow(2, place);
            continue;
        }
        result += m_mapNum[byte[i]] * pow(2, place);
    }
    return result;
}
