#ifndef LINTEGER_H
#define LINTEGER_H

#include <string>
#include <vector>
#include <map>

class LInteger
{
public:
    LInteger(const std::string& value, int base=10);
    LInteger& operator=(const LInteger& value);
    LInteger(const LInteger& value);
    
    std::string hex(void) const;
    std::string binary(void) const;
    long long decimal(void);
    
    LInteger& operator&(const LInteger& right);
    LInteger& operator|(const LInteger& right);
    LInteger& operator~(void);

    LInteger& operator<<(size_t n);
    LInteger& rightShiftInLogic(size_t n);
    LInteger& rightShiftInArithMetic(size_t n);

    static LInteger B2U(const LInteger& val);
    static LInteger B2T(const LInteger& val);
    static LInteger U2B(const LInteger& val);
    static LInteger U2T(const LInteger& val);
    static LInteger T2U(const LInteger& val);
    static LInteger T2B(const LInteger& val);
    static void setLittleEndian(bool littleEndian);

private:
    void init(const std::string& value, int base);
    long long pow(int base, int n) const;
    unsigned long long toNumber(const std::string& str, int base);
    std::string toBinary(unsigned long long number);
    void swapBit(std::string& str);
    void swapByte(std::string& str);
    void swap(std::string &str, int i, int j);
    void fulfillByte(std::string& binary, bool isSigned);
    std::string O2T(const std::string& binary);
    long long binaryToDecimal(const char *byte, size_t size, bool isSigned = false) const;

private:
    std::string m_number;
    bool m_signed;
    static bool m_littleEndian;
    static std::map<char, int> m_mapNum;
    static std::map<int, char> m_mapStr;
};

#endif
