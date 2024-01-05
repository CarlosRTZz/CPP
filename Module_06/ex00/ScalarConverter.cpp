#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void) rhs;
	return (*this);
}
