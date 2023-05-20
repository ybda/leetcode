#include <iostream>
#include <string>


bool isPalindrome1(int x) {
	if (x < 0) return false;
	if (x < 10) return true;

	std::string s = std::to_string(x);
	const char* sc = s.c_str();
	for (int i = 0; i < s.size() / 2; i++) {
		if (sc[i] != sc[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

bool isPalindrome2(int x) {
	if (x < 0) return false;
	if (x < 10) return true;

	std::string s = std::to_string(x);
	const char* sc = s.c_str();
	char* sr = new char[s.size()];

	for (int i = s.size() - 1, j = 0; i >= 0; i--, j++) {
		sr[j] = sc[i];
	}

	bool polindrome = true;
	for (int i = 0; i < s.size(); i++) {
		if (sr[i] != sc[i]) {
			polindrome = false;
		}
	}

	delete[] sr;

	return polindrome;
}

bool isPalindrome(int x) {
    if (x < 0) return false;
    int reversed = 0, original = x;
    do {
        reversed = reversed * 10 + original % 10;
        original /= 10;
    } while(original != 0);
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