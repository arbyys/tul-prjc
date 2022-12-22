#include <utility>
#include <iostream>
#include <cstring>
#include "RuleOfThreeAndFive.h"

Rule_of_three::Rule_of_three(const char * s, std::size_t n) : cstring (new char[n]) {
	std::memcpy(cstring, s, n);
}

Rule_of_three::Rule_of_three(const char *s): Rule_of_three(s, std::strlen(s) + 1){}

Rule_of_three::Rule_of_three(const Rule_of_three& other): Rule_of_three(other.cstring){}

Rule_of_three::~Rule_of_three() {
	std::cout << "deleting  " << cstring << " " << std::endl;
	delete[] cstring;
}
Rule_of_three & Rule_of_three::operator=(const Rule_of_three& other) {
	if (this == &other) return *this;
	std::size_t n{ std::strlen(other.cstring) + 1 };
	char * new_cstring = new char[n];
	std::memcpy(new_cstring, other.cstring, n);
	delete[] cstring;
	cstring = new_cstring;
	return *this;
}

Rule_of_three::operator const char *() const {
	return cstring;
}

//rule of five
Rule_of_three::Rule_of_three(Rule_of_three && other) : cstring(std::exchange(other.cstring, nullptr)) {}

Rule_of_three& Rule_of_three::operator=(Rule_of_three&& other) noexcept {
	std::swap(cstring, other.cstring);
	return *this;
}
