#include "ScalarConverter.hpp"

int main() {
	ScalarConverter test;
	std::string value;
	std::cout << "Type a number : ";
	std::cin >> value;

	// std::cout << value << std::endl;

	test.convert(value);
}