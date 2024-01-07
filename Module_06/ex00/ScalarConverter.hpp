#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private :
		bool isDisplayable(std::string strToCheck);
		bool isChar(std::string strToCheck);
		bool isInt(std::string strToCheck);

	public :
	
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		
		ScalarConverter &operator=(const ScalarConverter &rhs);

		static void convert(std::string toConvert);
};

#endif