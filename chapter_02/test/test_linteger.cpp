#include <catch2/catch_test_macros.hpp>
#include "../include/linteger.h"
#include <string>

using namespace std;

TEST_CASE("positive")
{
    LInteger integer(6);
    REQUIRE(string("0110") == integer.toBinary(4, LInteger::LSign_Magnitude));
    REQUIRE(string("0110") == integer.toBinary(4, LInteger::LOne_Complement));
    REQUIRE(string("0110") == integer.toBinary(4, LInteger::LTwo_Complement));
}

TEST_CASE("negative")
{
    LInteger integer(-6);
    REQUIRE(string("1110") == integer.toBinary(4, LInteger::LSign_Magnitude));
    REQUIRE(string("1001") == integer.toBinary(4, LInteger::LOne_Complement));
    REQUIRE(string("1010") == integer.toBinary(4, LInteger::LTwo_Complement));

    REQUIRE(string("11111010") == integer.toBinary(8, LInteger::LTwo_Complement));
}

TEST_CASE("decimal")
{
    LInteger integer(50);
    REQUIRE(string("50") == integer.toDecimal());
}

TEST_CASE("hex")
{
    LInteger integer(50);
    REQUIRE(string("32") == integer.toHex());
}
