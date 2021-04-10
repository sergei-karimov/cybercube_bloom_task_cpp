//
// Created by Sergei Karimov on 09.04.2021.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>
#include "../src/Bits.h"

int main(int argc, char *argv[]) {
    int result = Catch::Session().run(argc, argv);

    return result;
}

TEST_CASE("When try to set second bit to true then should be true", "[Bits]") {
    Bits bits = Bits(10);
    bits.setFor(1);
    REQUIRE(bits.checkOf(0) == false);
    REQUIRE(bits.checkOf(1) == true);
    REQUIRE(bits.checkOf(2) == false);
}

TEST_CASE("When try to set a bit outside the array then throw out_of_range", "[Bits]") {
    Bits bits = Bits(10);
    REQUIRE_THROWS_AS(bits.setFor(-1), std::out_of_range);
}

TEST_CASE("When try to set a very big index then throw out_of_range", "[Bits]") {
    Bits bits = Bits(10);
    REQUIRE_THROWS_AS(bits.setFor(INT32_MAX), std::out_of_range);
}
