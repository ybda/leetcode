#include <iostream>
#include <vector>
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
    std::cout << arrStr<std::string>(fizzBuzz(3)) << '\n';
    std::cout << arrStr<std::string>(fizzBuzz(5)) << '\n';
    std::cout << arrStr<std::string>(fizzBuzz(15)) << '\n';
}