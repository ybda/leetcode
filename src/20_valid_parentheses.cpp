#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

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
    std::cout << isValid("()") << std::flush
              << isValid("()[]{}")
              << isValid("()[]{}")
              << isValid("(){}")
              << isValid("{}()")
              << isValid("{[]}")
              << !isValid("([]{}") << std::flush
              << !isValid("(") << std::flush
              << !isValid("(){}}{") << std::flush
              << !isValid("(}{)") << std::flush
              << !isValid("]") << std::flush
              << !isValid("){") << std::flush
              << !isValid("(]");
}
