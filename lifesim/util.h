#pragma once

#include <cstdint>
#include <vector>

namespace lifesim {

template <typename T>
std::vector<T> SliceVector(std::vector<T> vec, int64_t start, int64_t length) {
    typename std::vector<T>::const_iterator first = vec.begin() + start;
    typename std::vector<T>::const_iterator last = vec.begin() + start + length;
    return std::vector<T>(first, last);
}

}
