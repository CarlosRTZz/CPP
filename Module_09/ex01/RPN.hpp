#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
	private :
		int myStdtoi(std::string toConvert);
		bool isValidInput(std::string input);
		bool isNumber(std::string toCheck);
		bool isOperator(char toCheck);
		int calculate(int nb1, int nb2, std::string tokken);
	public :
		RPN(void);
		RPN(const RPN & copy);
		~RPN(void);

		RPN&operator=(const RPN & rhs);
		void execRpn(std::string toCalculate);
};

#endif