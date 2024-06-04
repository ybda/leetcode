#include <cassert>
#include "util.h"

unsigned long factorialRecursion(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

unsigned long factorialNoRecursion(unsigned int n) {
    unsigned long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    TestCase<unsigned long> testCases[] = {
            {0, 1},
            {1, 1},
            {2, 2},
            {3, 6},
            {4, 24},
            {5, 120},
            {6, 720},
            {7, 5040},
            {8, 40320},
            {9, 362880},
            {10, 3628800},
            {11, 39916800},
            {12, 479001600},
            {13, 6227020800},
            {14, 87178291200},
            {15, 1307674368000},
    };

    for (const auto& testCase : testCases) {
        unsigned long output = factorialRecursion(testCase.input);
        assert(output == testCase.expected);

        output = factorialNoRecursion(testCase.input);
        assert(output == testCase.expected);
    }
}