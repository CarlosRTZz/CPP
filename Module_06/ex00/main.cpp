#include "ScalarConverter.hpp"

int main() {
	ScalarConverter test;
	std::string value;
	std::cout << "Type a number : ";
	std::cin >> value;

	std::cout << "Check Float : " << value << " = " << test.isFloat(value) << std::endl;
	std::cout << "Check Double : " << value << " = " << test.isDouble(value) << std::endl;
	std::cout << "Check Other : " << value << " = " << test.isOther(value) << std::endl;
}