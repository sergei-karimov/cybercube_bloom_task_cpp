//
// Created by Sergei Karimov on 09.04.2021.
//

#ifndef CYBERCUBE_BLOOM_TASK_CPP_BITS_H
#define CYBERCUBE_BLOOM_TASK_CPP_BITS_H

#include <vector>
#include <string>
#include <sstream>

class Bits {
private:
    std::vector<bool> bits;

public:
    Bits();
    explicit Bits(size_t size);
    void setFor(int index);
    bool checkOf(int index);
};

#endif //CYBERCUBE_BLOOM_TASK_CPP_BITS_H
