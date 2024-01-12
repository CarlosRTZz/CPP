#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
	private :
		static bool isDisplayable(std::string strToCheck);
		static bool isChar(std::string strToCheck);
		static bool isInt(std::string strToCheck);
		static bool isFloat(std::string strToCheck);
		static bool isDouble(std::string strToCheck);
		static bool isOther(std::string strToCheck);

		static void	printChar(char c);
		static void	printInt(int i);
		static void	printFloat(float f);
		static void	printDouble(double d);
		static void printOther(std::string other);

		static void toChar(std::string strToConvert);
		static void toInt(std::string strToConvert);
		static void toFloat(std::string strToConvert);
		static void toDouble(std::string strToConvert);

	public :
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		
		ScalarConverter &operator=(const ScalarConverter &rhs);

		static void convert(std::string toConvert);
};

#endif