#include <cassert>
#include <unordered_map>
#include "util.h"

bool isPossibleToSplit(const std::vector<int>& nums) {
    std::unordered_map<int, int> count;

    for (int n : nums) {
        count[n]++;
    }

    for (auto& pair : count) {
        if (pair.second > 2) {
            return false;
        }
    }

    return true;
}

int main() {
    TestCase2<std::vector<int>, bool> testCases[] = {
            {{1,1,2,2,3,4},  true},
            {{1,1,1,1},  false},
    };

    for (const auto& testCase : testCases) {
        auto output = isPossibleToSplit(testCase.input);
        assert(output == testCase.expected);
    }
}