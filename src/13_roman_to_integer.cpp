#include <cassert>
#include "util.h"

namespace romanNumParser {
    static int getValue(const char *s){
        switch(*s) {
            case 'I': return (s[1] == 'V' || s[1] == 'X') ? -1 : 1;
            case 'X': return (s[1] == 'L' || s[1] == 'C') ? -10 : 10;
            case 'C': return (s[1] == 'D' || s[1] == 'M') ? -100 : 100;
            case 'V': return 5;
            case 'L': return 50;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }

    static int parse(const char *s) {
        int result = 0;

        for(; *s != '\0'; s++) {
            result += getValue(s);
        }

        return result;
    }
}

int main() {
    TestCase2<const char*, int> testCases[] = {
            {"I",        1},
            {"III",      3},
            {"IV",       4},
            {"V",        5},
            {"VI",       6},
            {"VII",      7},
            {"VIV",      9},
            {"XXXI",     31},
            {"XXXVII",   37},
            {"LXXI",     71},
            {"LXXXIV",   84},
            {"LXXXV",    85},
            {"LXXXVI",   86},
            {"XCIX",     99},
            {"C",        100},
            {"CCX",      210},
            {"MMMCMXLI", 3941}
    };

    for (const auto& testCase : testCases) {
        unsigned long output = romanNumParser::parse(testCase.input);
        assert(output == testCase.expected);
    }
}