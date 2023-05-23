#include <iostream>

int reverse(int x) {
    int reversed = 0;
    do {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    } while(x != 0);
    return reversed;
}

int main() {
    std::cout << (reverse(1) == 1)
              << (reverse(21) == 12)
              << (reverse(43) == 34)
              << (reverse(156) == 651)
              << (reverse(0) == 0)
              << (reverse(10) == 1)
              << (reverse(20) == 2)
              << (reverse(-27) == -72)
              << (reverse(-245) == -542)
              << (reverse(-7488) == -8847)
              << (reverse(-1) == -1);
}