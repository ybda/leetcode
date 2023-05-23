#include <iostream>


bool isPalindrome(const int x) {
    if (x < 0) return false;
    int reversed = 0, origin = x;
    do {
        reversed = reversed * 10 + origin % 10;
        origin /= 10;
    } while(origin != 0);
    return reversed == x;
}


int main() {
	std::cout << isPalindrome(121);
	std::cout << isPalindrome(2112);
	std::cout << isPalindrome(1001);
    std::cout << isPalindrome(66);
    std::cout << isPalindrome(0);
	std::cout << !isPalindrome(-121);
	std::cout << !isPalindrome(10);
	std::cout << !isPalindrome(1010);
	std::cout << !isPalindrome(787887);
}