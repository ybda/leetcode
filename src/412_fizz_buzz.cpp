#include <iostream>
#include <vector>
#include <cassert>
#include "util.h"

std::vector<std::string> fizzBuzz(const int n) {
    auto* rp = new std::string[n];
    std::string s;
    bool three, five;
    for (int i = 1; i <= n; i++) {
        three = i % 3 == 0; five = i % 5 == 0;
        if (three) {
            if (five) {
                s = "FizzBuzz";
            } else {
                s = "Fizz";
            }
        } else if (five) {
            s = "Buzz";
        } else {
            s = std::to_string(i);
        }
        rp[i-1] = std::move(s);
    }
    std::vector<std::string> rs(rp, rp + n);
    delete[] rp;
    return rs;
}


int main() {
    std::cout << "412_fizz_buzz\n";

    TestCase2<int, std::vector<std::string>> testCases[] = {
            {3, {"1", "2", "Fizz"}},
            {5,  {"1", "2", "Fizz", "4", "Buzz"}},
            {15,  {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"}},
    };

    for (const auto& testCase : testCases) {
        const auto output = fizzBuzz(testCase.input);
        assert(util::arraysEqual(output, testCase.expected));
    }
}