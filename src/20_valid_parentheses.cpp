#include <string>
#include <map>
#include <stack>
#include <cassert>
#include "util.h"

// ({[
bool isValid(const std::string &s) {
    std::stack<char> stk;
    for (char c: s) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                stk.push(c);
                break;
            default:
                if (!stk.empty() &&
                    (stk.top() == '(' && c == ')'
                     || stk.top() == '{' && c == '}'
                     || stk.top() == '[' && c == ']')) {
                    stk.pop();
                } else {
                    return false;
                }
                break;
        }
    }
    return stk.empty();
}


int main() {
    TestCase2<std::string, bool> testCases[] = {
            {"()",  true},
            {"()[]{}",  true},
            {"(){}",  true},
            {"{}()",  true},
            {"{[]}",  true},
            {"([]{}",  false},
            {"(",  false},
            {"(){}}{",  false},
            {"(}{)",  false},
            {"]",  false},
            {"){",  false},
            {"(]",  false},
    };

    for (const auto& testCase : testCases) {
        unsigned long output = isValid(testCase.input);
        assert(output == testCase.expected);
    }
}
