#include "BloomFilter.h"

bool BloomFilter::loadFromFile(const std::string& fileName) {
    std::ifstream input(fileName);
    if (!input) {
        std::cout << "Cannot open input file.\n";
        return false;
    }

    std::string word;
    std::vector<std::string> words;
    while(std::getline(input, word)) {
        words.push_back(word);
    }

    calculateParameters((int)words.size(), 0.01);
    bits = Bits(this->numberOfBits);

    for(const auto& item : words)
        add(item);

    return true;
}

bool BloomFilter::add(const std::string& word) {
    std::vector<int> indexes = calculateIndexes(word);
    for(auto idx : indexes) {
        try {
            this->bits.setFor(idx);
        }catch (std::exception & ex) {
            return false;
        }
    }

    return true;
}

bool BloomFilter::isContain(const std::string& word) {
    std::vector<int> indexes = calculateIndexes(word);
    for(auto idx : indexes) {
        if (!this->bits.checkOf(idx)) {
            return false;
        }
    }

    return true;
}

BloomFilter::BloomFilter(int size, double coefficient) {
    calculateParameters(size, coefficient);

    bits = Bits(this->numberOfBits);
}

void BloomFilter::calculateParameters(int numberOfItems, double errorRate) {
    BloomFilter::size = numberOfItems;
    BloomFilter::coefficient = errorRate;
    numberOfBits = (int)round(-(BloomFilter::size * log2(BloomFilter::coefficient)) / (log2(2.0) * log2(2.0)));
    numberOfHashes = (int)round(round(numberOfBits / BloomFilter::size) * log2(2.0));
}

std::vector<int> BloomFilter::calculateIndexes(const std::string& word) const {
    std::vector<int> indexes = std::vector<int>();
    for (int i = 0; i < this->numberOfHashes; i++) {
        indexes.push_back(Hash::calculate(word, i) % numberOfBits);
    }

    return indexes;
}

BloomFilter::BloomFilter() = default;
