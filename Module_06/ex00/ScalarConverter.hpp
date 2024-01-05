#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	public :
	
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		
		ScalarConverter &operator=(const ScalarConverter &rhs);

		void convert(std::string toConvert);
};

#endif