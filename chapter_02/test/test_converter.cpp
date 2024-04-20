#include <catch2/catch_test_macros.hpp>
#include "../include/converter.h"


TEST_CASE()
{
    REQUIRE("100" == toString(100, 10));
    REQUIRE("0144" == toString(100, 8));

    REQUIRE("0b1100100" == toString(100, 2));
    REQUIRE("0b1110011010011111111000" == toString(0x39A7F8, 2));
    REQUIRE("0b11010101111001001100" == toString(0xD5E4C, 2));

    REQUIRE("0x64" == toString(100, 16));
    REQUIRE("0x12F" == toString(0b00100101111, 16));
    REQUIRE("0xDCF6" == toString(0b01101110011110110, 16));

    REQUIRE("0xA7" == toString(167, 16));
    REQUIRE("0b10100111" == toString(167, 2));

    REQUIRE("0x3E" == toString(62, 16));
    REQUIRE("0b111110" == toString(62, 2));
}
