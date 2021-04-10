//
// Created by Sergei Karimov on 10.04.2021.
//
#include "Hash.h"

int Hash::calculate(const std::string& word, int salt) {
    std::stringstream item;
    item << salt << word;
    return simpleHash(item.str());
}

int Hash::simpleHash(const std::string& item) {
    int seed = 5381;
    int result = 0;

    for (auto ch : item) {
        result = (int)round((seed * result + (int)ch) & INT32_MAX);
    }

    return result;
}
