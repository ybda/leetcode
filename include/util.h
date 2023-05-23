#pragma once
#include <iostream>
#include <vector>
#include <sstream>

template<typename T>
std::string arrStr(const std::vector<T>& v) {
    if (v.empty()) {
        return "[]";
    }

    std::ostringstream oss;
    oss << "[\"";
    for (auto it = v.begin(); it != v.end(); ++it) {
        oss << *it;
        if (std::next(it) != v.end()) {
            oss << "\",\"";
        }
    }
    oss << "\"]";

    return oss.str();
}

template<typename T>
std::string arrStr(const T* arr, const size_t size) {
    if (size == 0) {
        return "[]";
    }

    std::ostringstream oss;
    oss << '[';
    for (size_t i = 0; i < size; ++i) {
        oss << arr[i];
        if (i != size - 1) {
            oss << ", ";
        }
    }
    oss << ']';

    return oss.str();
}