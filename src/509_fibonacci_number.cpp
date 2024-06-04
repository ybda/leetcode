#include <cassert>
#include "util.h"

// Time complexity: O(n) | Space complexity: O(1)
// Iterative Solution / Space Optimized Soln.
static unsigned long fib(int n) {
    if(n <= 1) {
        return n;
    }

    unsigned long prev2 = 0,
            prev = 1;
    for(int i = 2; i <= n; i++) {
        unsigned long curr_i = prev2 + prev;
        prev2 = prev;
        prev = curr_i;
    }

    return prev;
}

int main() {
    TestCase<unsigned long> testCases[] = {
            {0,  0},
            {1,  1},
            {2,  1},
            {3,  2},
            {12, 144},
            {40, 102334155},
            {61, 2504730781961}
    };

    for (const auto& testCase : testCases) {
        unsigned long output = fib(testCase.input);
        assert(output == testCase.expected);
    }
}