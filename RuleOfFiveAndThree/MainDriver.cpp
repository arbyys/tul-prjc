#include "RuleOfThreeAndFive.h"

int main() {

	Rule_of_three o1("Ahoj");
	std::cout << o1 << std::endl;

	Rule_of_three o2(o1); // or o2 {o1}
	std::cout << o2 << std::endl;

	Rule_of_three o3("POKUS");
	std::cout << o3 << std::endl;

	o3 = o2;
	std::cout << o3 << std::endl;
	std::cout << o2 << std::endl;
	std::cout << "=====" << std::endl;

	
	//MOVEs
	
	Rule_of_three o5("o5"), o6("o6");
	std::cout << "Before move " << o5 << std::endl;
	std::cout << "Before move " << o6 << std::endl;

	o5 = std::move(o6);
	std::cout << "After move " << o5 << std::endl;
	std::cout << "After move " << o6 << std::endl;
	
	return 0;

}