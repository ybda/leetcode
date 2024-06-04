#pragma once

#include <iostream>
#include <vector>
#include <sstream>

namespace util {
    template<typename T>
    static std::string arrStr(const std::vector<T> &v) {
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
    static std::string arrStr(const T *arr, const size_t size) {
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

    static inline size_t strlen(const char* s) {
        size_t i = 0;
        for (; s[i] != '\0'; i++) {
        }
        return i;
    }

    static inline unsigned short hexCharToNum(char c) {
        return c > 64 ? c - 55 : c - 48;
    }

    static inline bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
}

template<typename T>
struct TestCase {
    T input;
    T expected;
};

template<typename T1, typename T2>
struct TestCase2 {
    T1 input;
    T2 expected;
};
