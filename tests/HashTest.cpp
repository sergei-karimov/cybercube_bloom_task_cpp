//
// Created by Sergei Karimov on 10.04.2021.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>
#include "../src/Hash.h"

TEST_CASE("When generate hash for A then return 263734", "[Bits]") {
    REQUIRE(Hash::calculate("A", 1) == 263734);
}
