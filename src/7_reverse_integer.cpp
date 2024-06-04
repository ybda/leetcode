#include <cmath>
#include <cassert>
#include "util.h"

int reverse(int x) {
    int upperLimit =  (pow(2,31) - 1)/10;
    int lowerLimit = -(pow(2,31)/10);

    int ans = 0;

    while(x){
        int lastDigit = x%10;

        if(ans <= upperLimit && ans >= lowerLimit){ // Checking if ans will be there in integer range only.
            int temp = ans * 10 + lastDigit;
            ans = temp;
            x/=10;
        }
        else{ // ans would exceed the int if multiplied by 10. Thus integer overflow occur
            return 0;
        }

    }
    return ans;
}

int reverseWithoutOverflowHandling(int x) {
    int reversed = 0;
    do {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    } while(x != 0);
    return reversed;
}

int main() {
    TestCase<int> testCases[] = {
            {1234,     4321},
            {-123,     -321},
            {120,      21},
            {123456,   654321},
            {789012,   210987},
            {890123,   321098},
            {901234,   432109},
            {1234567,  7654321},
            {2345678,  8765432},
            {3456789,  9876543},
            {4567890,  987654},
            {5678901,  1098765},
            {6789012,  2109876},
            {-7890123,  -3210987},
            {8901234,  4321098},
            {9012345,  5432109},
            {12345678, 87654321},
            {23456789, 98765432},
            {34567890, 9876543},
            {45678901, 10987654},
            {56789012, 21098765},
            {67890123, 32109876},
            {78901234, 43210987},
            {89012345, 54321098},
            {901234536, 635432109},
            {-901234536, -635432109},
            {1534236469, 0} // overflow case
    };

    for (const auto& testCase : testCases) {
        unsigned long output = reverse(testCase.input);
        assert(output == testCase.expected);
    }
}