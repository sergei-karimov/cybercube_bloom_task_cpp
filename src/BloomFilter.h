#ifndef CYBERCUBE_BLOOM_TASK_CPP_BLOOMFILTER_H
#define CYBERCUBE_BLOOM_TASK_CPP_BLOOMFILTER_H

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <utility>
#include <fstream>

#include "Bits.h"
#include "Hash.h"

class BloomFilter {
private:
    int size = 1000;
    double coefficient = 0.01;
    int numberOfBits = 0;
    int numberOfHashes = 0;
    Bits bits;
    std::vector<int> calculateIndexes(const std::string& word) const;

public:
    BloomFilter();
    BloomFilter(int size, double coefficient);
    bool loadFromFile(const std::string& fileName);
    bool add(const std::string& word);
    bool isContain(const std::string& word);

    void calculateParameters(int numberOfItems, double errorRate);
};

#endif //CYBERCUBE_BLOOM_TASK_CPP_BLOOMFILTER_H
