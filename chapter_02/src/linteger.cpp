#include "../include/linteger.h"
#include <cmath>
#include <cstdlib>
#include "../include/debug.h"

LInteger::LInteger(long long value)
{
    m_value = value;
}

void LInteger::setValue(long long value)
{
    m_value = value;
}

std::string LInteger::toDecimal(void)
{
    resetChars();
    int i = 0;
    long long value = m_value;
    while (value > 0)
    {
        int result = value % 10;
        m_chars[i] = result;
        i++;
        value /= 10;
    }
    m_len = i;
    return toString();
}

std::string LInteger::toHex(void)
{
    resetChars();
    int i = 0;
    long long value = m_value;
    while (value > 0)
    {
        int result = value % 16;
        m_chars[i] = result;
        i++;
        value /= 16;
    }
    m_len = i;
    return toString();
}

std::string LInteger::toBinary(LType dataType, LCode code)
{
    return toBinary(getLength(dataType), code);
}

std::string LInteger::toBinary(int length, LCode code)
{
    computeBinary(m_value, length, code);
    return toString();
}

void LInteger::computeBinary(long long value, int length, LCode code)
{
    DBGprint("start compute binary, value=%d, len=%d, code=%s\n", value, length, getCodeString(code).c_str());
    resetChars();
    m_len = length;
    if (value > 0)
    {
        binaryForPositive(value);
    }
    else if (value == 0)
    {
        //no need to compute
    }
    else
    {
        binaryForNegative(value, code);
    }
}

int LInteger::getLength(LType dataType) const
{
    switch (dataType)
    {
        case LInt_4: return 4;
        case LUInt_4: return 4;
        case LInt_8: return 8;
        case LUInt_8: return 8;
        case LInt_16: return 16;
        case LUInt_16: return 16;
        case LInt_32: return 32;
        case LUInt_32: return 32;
        case LInt_64: return 64;
        case LUInt_64: return 64;    
        default:
            throw "unsupport data type";
            break;
    }
}

std::string LInteger::getCodeString(LCode code) const
{
    switch (code)
    {
        case LSign_Magnitude: return "Sign_Magnitude";
        case LOne_Complement: return "One_Complement";
        case LTwo_Complement: return "Two_Complement";
        default: return "unknown";
    }
}

void LInteger::binaryForPositive(long long value)
{
    int i = 0;
    while (value > 0)
    {
        int result = value % 2;
        m_chars[i] = result;
        i++;
        value /= 2;
    }
}

void LInteger::binaryForNegative(long long value, LCode code)
{
    value = std::llabs(value);
    int i = 0;
    while (value > 0)
    {
        int result = value % 2;
        m_chars[i] = result;
        DBGprint("pos: %d, bit: %d\n", i, result);
        i++;
        value /= 2;
    }
    int signPos = getSignPos(i);
    DBGprint("signPos: %d\n", signPos);
    m_chars[signPos] = 1;
    if (code == LSign_Magnitude)
    {
        return;
    }

    if (code == LOne_Complement)
    {
        oneComplement(signPos);
    }
    else if (code == LTwo_Complement)
    {
        twoComplement(signPos);
    }
    for (size_t i = signPos; i < m_chars.size(); i++)
    {
        m_chars[i] = 1;
    }
}

std::string LInteger::toString(void)
{
    static std::array<char, 16> chars = {'0', '1', '2', '3', 
                                        '4', '5', '6', '7',
                                        '8', '9', 'A', 'B',
                                        'C', 'D', 'E', 'F'};
    std::string result;
    for (int i = m_len - 1; i >= 0; i--)
    {
        result.push_back(chars[m_chars[i]]);
    }
    return result;
}

void LInteger::resetChars(void)
{
    for (int i = 0, size = m_chars.size(); i < size; ++i)
    {
        m_chars[i] = 0;
    }
}

int LInteger::getSignPos(int len)
{
    return (len/4 + 1) * 4 - 1;
}

void LInteger::oneComplement(int signPos)
{
    DBGprint("start one complement\n");
    for (size_t i = 0; i < signPos; i++)
    {
        m_chars[i] = (m_chars[i] == 0) ? 1 : 0;
        DBGprint("pos: %d, bit: %d\n", i, m_chars[i]);
    }
}

void LInteger::twoComplement(int signPos)
{
    oneComplement(signPos);
    DBGprint("start two complement\n");
    int result = 1;
    int i = 0;
    while (result > 0)
    {
        if (m_chars[i] == 0)
        {
            m_chars[i] = 1;
            DBGprint("pos: %d, bit: %d\n", i, m_chars[i]);

            result = 0;
        }
        else
        {
            m_chars[i] = 0;
            DBGprint("pos: %d, bit: %d\n", i, m_chars[i]);

            result = 1;
            ++i;
        }
    }
}
