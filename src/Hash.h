//
// Created by Sergei Karimov on 10.04.2021.
//

#ifndef CYBERCUBE_BLOOM_TASK_CPP_HASH_H
#define CYBERCUBE_BLOOM_TASK_CPP_HASH_H

#include <string>
#include <sstream>
#include <cstdint>

class Hash {
private:
    static int simpleHash(const std::string& item);

public:
    static int calculate(const std::string& word, int salt);
};

#endif //CYBERCUBE_BLOOM_TASK_CPP_HASH_H
