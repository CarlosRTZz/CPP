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

bool ScalarConverter::isDisplayable(std::string strToCheck) {
	for (int i = 0; strToCheck.size(); i++) {
		if (!isprint(strToCheck[i]))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isChar(std::string strToCheck) {
	if (strToCheck.size() == 1 && !isdigit(strToCheck[0]))
		return (1);
	return (0);
}

bool ScalarConverter::isInt(std::string strToCheck) {
	int i = 0;
	if (strToCheck[i] == '-' || strToCheck[0] == '+')
		i++;
	while (strToCheck[i])
	{
		if (!isdigit(strToCheck[i]))
			return (0);
		i++;
	}
	return (1);
}

static void ScalarConverter::convert(std::string toConvert) {
	if (!isDisplayable(toConvert))
	{
		std::cout << "Non displayable character are forbidden!" << std::endl;
		return ;
	}
}