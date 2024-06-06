#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "util.h"


size_t getSmallestStringSize(const std::vector<std::string>& ss) {
    if (ss.empty()) return 0;
    size_t r = ss[0].size();
    for (const std::string& s : ss) {
        if (s.size() < r) {
            r = s.size();
        }
    }
    return r;
}


/** Constraints:
- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] consists of only lowercase English letters.
 */
std::string longestCommonPrefix(const std::vector<std::string>& ss) {
    std::string rs;
    size_t sm_str_sz = getSmallestStringSize(ss);

    for (size_t i = 0; i < sm_str_sz; i++) {
        bool should_add_letter = true;
        char ch = ss[0][i];
        for (const auto & s : ss) {
            if (s[i] != ch) {
                should_add_letter = false;
                break;
            }
        }
        if (should_add_letter) {
            rs.push_back(ch);
        } else {
            break;
        }
    }
    return rs;
}


int main() {
    TestCase2<std::vector<std::string>, std::string> testCases[] = {
            {{"flower","flow","flight"},  "fl"},
            {{"jhtwdsggg","jhtwfdsgghshrgggshw","jhtwbvvvn"},  "jhtw"},
            {{"dog","racecar","car"},  ""},
            {{"cir","car"},  "c"},
    };

    for (const auto& testCase : testCases) {
        auto output = longestCommonPrefix(testCase.input);
        assert(output == testCase.expected);
    }
}
