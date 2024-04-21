#include <string>
#include <array>

class LInteger
{
    #define INT_MAX_LEN 64
public:
    LInteger(long long val);
    enum LType
    {
        LInt_4,
        LUInt_4,
        LInt_8,
        LUInt_8,
        LInt_16,
        LUInt_16,
        LInt_32,
        LUInt_32,
        LInt_64,
        LUInt_64,
    };
    enum LCode
    {
        LSign_Magnitude = 0,
        LOne_Complement,
        LTwo_Complement,
    };

    void setValue(long long value);
    std::string toDecimal(void);
    std::string toHex(void);
    std::string toBinary(LType dataType, LCode code);
    std::string toBinary(int length, LCode code);

private:
    void computeBinary(long long value, int length, LCode code);
    int getLength(LType dataType) const;
    std::string getCodeString(LCode code) const;
    void binaryForPositive(long long value);
    void binaryForNegative(long long value, LCode code);
    std::string toString(void);
    void resetChars(void);
    int getSignPos(int len);
    void oneComplement(int signPos);
    void twoComplement(int signPos);

private:
    long long m_value;
    std::array<int, INT_MAX_LEN> m_chars;
    int m_len;
};
