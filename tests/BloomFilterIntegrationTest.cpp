//
// Created by Sergei Karimov on 10.04.2021.
//

#include <catch2/catch_all.hpp>
#include "../src/BloomFilter.h"

TEST_CASE("When read data from file then filter created and bla-bla-bla word in it", "[Bloom filter]") {
    BloomFilter filter = BloomFilter();
    filter.loadFromFile("../../data/wordlist.txt");

    REQUIRE(filter.isContain("molecule's") == true);
    REQUIRE(filter.isContain("oh-no-i-know") == false);
}