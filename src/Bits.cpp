//
// Created by Sergei Karimov on 09.04.2021.
//

#include "Bits.h"

void Bits::setFor(int index) {
    if (index < 0 || index >= bits.size()) {
        std::stringstream message;
        message << "Index must be from 0 to " << (bits.size() - 1) << std::endl;
        throw std::out_of_range(message.str());
    }

    bits[index] = true;
}

bool Bits::checkOf(int index) {
    return bits[index];
}

Bits::Bits(size_t size) {
    bits = std::vector<bool>(size);
}

Bits::Bits() = default;
