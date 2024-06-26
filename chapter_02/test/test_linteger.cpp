#include <catch2/catch_test_macros.hpp>
#include "../include/linteger.h"
#include <string>

using namespace std;

TEST_CASE("constructor")
{
    LInteger::setLittleEndian(false);
    LInteger integer("6");
    REQUIRE("06" == integer.hex());
    REQUIRE("00000110" == integer.binary());

    integer = LInteger("-122");
    REQUIRE("86" == integer.hex());
    REQUIRE("10000110" == integer.binary());
}

TEST_CASE("little-endian")
{
    LInteger::setLittleEndian(true);
    LInteger integer("6000");
    REQUIRE("7017" == integer.hex());
}

TEST_CASE("decimal")
{
    LInteger::setLittleEndian(false);
    LInteger integer("10");
    REQUIRE(10 == integer.decimal());
    REQUIRE("0A" == integer.hex());
    REQUIRE("00001010" == integer.binary());

    integer = LInteger("-10");
    REQUIRE(-10 == integer.decimal());
    REQUIRE("F6" == integer.hex());
    REQUIRE("11110110" == integer.binary());
}

TEST_CASE("hex")
{
    LInteger::setLittleEndian(false);
}

TEST_CASE("binary")
{
    LInteger::setLittleEndian(false);
    LInteger integer("39A7F8", 16);
    REQUIRE("001110011010011111111000" == integer.binary());
}
