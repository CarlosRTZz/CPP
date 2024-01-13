#include "ScalarConverter.hpp"
#include <cmath>

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
	for (int i = 0; strToCheck[i]; i++) {
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

void ScalarConverter::printChar(char c) {
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printFloat(float f) {
	float decimalPart = f - std::floor(f);

	if (decimalPart != 0.0)
		std::cout << ".0f" << std::endl;
	else 
		std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	double decimalPart = d - std::floor(d);

	if (decimalPart != 0.0)
		std::cout << ".0" << std::endl;
}

void ScalarConverter::toChar(std::string strToConvert) {
	char c = strToConvert[0];
	ScalarConverter::printChar(c);
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	ScalarConverter::printFloat(static_cast<float>(c));
	ScalarConverter::printDouble(static_cast<double>(c));
}

void ScalarConverter::toInt(std::string strToConvert) {
	int num = 0;
	std::stringstream ss(strToConvert);
	ss >> num;
	if (ss.fail()) {
		std::cout << "Error while converting int!!" << std::endl;
		return ;
	}
	ScalarConverter::printChar(static_cast<char>(num));
	std::cout << "int: " << num << std::endl;
	ScalarConverter::printFloat(static_cast<float>(num));
	ScalarConverter::printDouble(static_cast<float>(num));
}

void ScalarConverter::toFloat(std::string strToConvert) {
	float num = 0;
	std::stringstream ss(strToConvert);
	ss >> num;
	if (ss.fail()) {
		std::cout << "Error while converting float!" << std::endl;
		return ;
	}
	ScalarConverter::printChar(static_cast<char>(num));
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	ScalarConverter::printFloat(static_cast<float>(num));
	ScalarConverter::printDouble(static_cast<double>(num)); 
}

void ScalarConverter::toDouble(std::string strToConvert) {
	double num = 0;
	std::stringstream ss(strToConvert);
	ss >> num;
	if (ss.fail()) {
		std::cout << "Error while converting double!" << std::endl;
		return ;
	}
	ScalarConverter::printChar(static_cast<char>(num));
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	ScalarConverter::printFloat(static_cast<float>(num));
	ScalarConverter::printDouble(static_cast<double>(num));
}

void ScalarConverter::toOther(std::string strToConvert) {
	std::cout << "int: impossible" << std::endl;
	std::cout << "char: impossible" << std::endl;

	if (strToConvert == "-inf" || strToConvert == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	if (strToConvert == "+inf" || strToConvert == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	if (strToConvert == "nan" || strToConvert == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convert(std::string toConvert) {
	if (!ScalarConverter::isDisplayable(toConvert))
	{
		std::cout << "Non displayable character are forbidden!" << std::endl;
		return ;
	}

	if (ScalarConverter::isChar(toConvert))
		ScalarConverter::toChar(toConvert);
	else if (ScalarConverter::isInt(toConvert))
		ScalarConverter::toInt(toConvert);
	else if (ScalarConverter::isFloat(toConvert))
		ScalarConverter::toFloat(toConvert);
	else if (ScalarConverter::isDouble(toConvert))
		ScalarConverter::toDouble(toConvert);
	else if (ScalarConverter::isOther(toConvert))
		ScalarConverter::toOther(toConvert);
	else
		std::cout << "Unknown type!" << std::endl;
}
