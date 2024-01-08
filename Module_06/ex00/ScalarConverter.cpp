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

bool ScalarConverter::isFloat(std::string strToCheck) {
	int i = 0;
	if (strToCheck[i] == '-' || strToCheck[0] == '+')
		i++;
	while (isdigit(strToCheck[i]) && strToCheck[i])
		i++;
	if (strToCheck[i] != '.')
		return (false);
	i++;
	while (isdigit(strToCheck[i]) && strToCheck[i])
		i++;
	if (strToCheck[i] == 'f' && i == (int)strToCheck.size() - 1)
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(std::string strToCheck)
{
	int i = 0;
	if (strToCheck[i] == '-' || strToCheck[0] == '+')
		i++;
	while (isdigit(strToCheck[i]) && strToCheck[i])
		i++;
	if (strToCheck[i] != '.')
		return (false);
	i++;
	while (isdigit(strToCheck[i]) && strToCheck[i])
		i++;
	if (i == (int)strToCheck.size())
		return (true);
	return (false);
}

bool ScalarConverter::isOther(std::string strToCheck) {
	if (strToCheck == "-inff" || strToCheck == "+inff" || strToCheck == "nanf" || strToCheck == "+inf" || strToCheck == "-inf" || strToCheck == "nan")
		return (true);
	return (false);
}

void ScalarConverter::toChar(std::string strToConvert) {
	char c = strToConvert[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
}

void ScalarConverter::convert(std::string toConvert) {
	if (!ScalarConverter::isDisplayable(toConvert))
	{
		std::cout << "Non displayable character are forbidden!" << std::endl;
		return ;
	}
}