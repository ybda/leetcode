#include <cmath>
#include <cassert>
#include "util.h"

std::string toHex(int num) {
    unsigned int ourNum = num;
    // Implicitly cast negative numbers.
    // -1 turns to the maximum number representable
    // as an unsigned int.

    std::string str; // Our result
    char ourArray[17] = "0123456789abcdef"; // We will pick from this set of characters

    // While our number exists, convert it into base 16.
    // We are going from left to right, so we need to reverse our result
    // when we return it.
    do {
        str += ourArray[ourNum % 16];
        ourNum /= 16;
    } while (ourNum);

    return {str.rbegin(), str.rend()};
}

int main() {
    TestCase2<int, std::string> testCases[] = {
            { 419, "1a3" },
            { 4660, "1234" },
            { 43968,"abc0" },
            { 10815, "2a3f" },
            { 9070, "236e" },
            { 8433, "20f1" },
            { 10737, "29f1" },
    };

    for (const auto& testCase : testCases) {
        auto output = toHex(testCase.input);
        assert(output == testCase.expected);
    }
}