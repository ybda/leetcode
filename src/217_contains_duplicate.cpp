#include <cassert>
#include <unordered_map>
#include "util.h"

bool containsDuplicate(const std::vector<int>& nums) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::unordered_map<int, int> dups;
    for (int num : nums){
        if(dups[num] >= 1){
            return true;
        } else {
            dups[num]++;
        }
    }

    return false;
}

int main() {
    TestCase2<std::vector<int>, bool> testCases[] = {
            {{1,2,3,1},  true},
            {{1,2,5,4},  false},
            {{1,1,1,3,3,4,3,2,4,2},  true},
    };

    for (const auto& testCase : testCases) {
        auto output = containsDuplicate(testCase.input);
        assert(output == testCase.expected);
    }
}