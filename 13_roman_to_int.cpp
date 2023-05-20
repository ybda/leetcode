#pragma once
#include <iostream>
#include <unordered_map>


std::unordered_map<char, short> ROMAN_N = {
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 }
};


int roman_to_int(const std::string& s) {
	short sz = s.size();
	const char* cstr = s.c_str();
	short* nums = new short[sz];
	
	for (short i = 0; i < sz; i++) {
		nums[i] = ROMAN_N[cstr[i]];
	}

	for (short i = 1; i < sz; i++) {
		if (nums[i] > nums[i - 1]) {
			nums[i - 1] = -nums[i - 1];
		}
	}

	short rs = 0;
	for (short i = 0; i < sz; i++) {
		rs += nums[i];
	}

	delete[] nums;
	return rs;
}

int main() {
	std::cout << "XXVII(27): " << roman_to_int("XXVII") << '\n';
	std::cout << "XXXIV(34): " << roman_to_int("XXXIV") << '\n';
	std::cout << "III(3): " << roman_to_int("III") << '\n';
	std::cout << "LVIII(58): " << roman_to_int("LVIII") << '\n';
	std::cout << "MCMXCIV(1994): " << roman_to_int("MCMXCIV") << '\n';
}