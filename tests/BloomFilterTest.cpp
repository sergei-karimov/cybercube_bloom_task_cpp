//
// Created by Sergei Karimov on 09.04.2021.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>
#include "../src/BloomFilter.h"

TEST_CASE("When add word with proper data then return true", "[Bloom filter]") {
    BloomFilter filter = BloomFilter(100, 0.01);
    filter.add("bla-bla-bla");
    REQUIRE(filter.isContain("bla-bla-bla") == true);
    REQUIRE(filter.isContain("oh-no-i-know") == false);
}

TEST_CASE("When check the known word should return true", "[Bloom filter]") {
    BloomFilter filter = BloomFilter(100, 0.01);
    filter.add("known");
    REQUIRE(filter.isContain("known") == true);
}

TEST_CASE("When check the unknown word should return false", "[Bloom filter]") {
    BloomFilter filter = BloomFilter(100, 0.01);
    filter.add("known");
    REQUIRE(filter.isContain("unknown") == false);
}
