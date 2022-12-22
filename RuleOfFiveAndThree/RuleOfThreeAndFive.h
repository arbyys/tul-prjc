#pragma once
#include <iostream>

class Rule_of_three {
private:
	char *cstring;
	Rule_of_three(const char * s, std::size_t n);
public:
	Rule_of_three(const char *s = "");
	Rule_of_three(const Rule_of_three& other);
	~Rule_of_three();
	Rule_of_three & operator=(const Rule_of_three& other);
	operator const char *() const;

	//rule of five
	Rule_of_three(Rule_of_three && other);
	Rule_of_three& operator=(Rule_of_three&& other) noexcept;

};