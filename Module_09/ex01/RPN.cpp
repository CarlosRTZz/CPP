#include "RPN.hpp"

RPN::RPN(void) {

}

RPN::RPN(const RPN & copy) {
	*this = copy;
}

RPN::~RPN(void) {

}

RPN &RPN::operator=(const RPN & rhs) {
	(void)rhs;
	return (*this);
}

bool RPN::isNumber(std::string toCheck) {
	if ((toCheck[0] == '-' || toCheck[0] ==  '+') && std::isdigit(toCheck[1])) {
		if (toCheck[2])
			return(0);
		return (1);
	} else if (std::isdigit(toCheck[0]) && !toCheck[1]) {
		return (1);
	}
	return (0);
}

bool RPN::isOperator(char toCheck) {
	return (toCheck == '+' || toCheck == '-' || toCheck == '/' || toCheck == '*');
}

int RPN::myStdtoi(std::string toConvert) {
	std::istringstream iss(toConvert);
	int value;
	try
	{
		iss >> value;
	}  catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (value);
}

bool RPN::isValidInput(std::string input) {
	int nbOfSign = 0;
	int numbers = 0;
	std::istringstream iss(input);
	std::string value;
	while (iss >> value) {
		if (this->isNumber(value)) {
			numbers++;
		} else if (this->isOperator(value[0]) && !value[1])
			nbOfSign++;
		else {
			return (0);
		}
	}
	if ((numbers - nbOfSign) != 1 || numbers < 2)
		return(0);
	return (1);
}

int RPN::calculate(int nb1, int nb2, std::string tokken) {
	switch (tokken[0]) {
		case '+' :
			return (nb1 + nb2);
		case '-' :
			return (nb1 - nb2);
		case '/' :
			return (nb1 / nb2);
		default :
			return (nb1 * nb2);
	}
}

void RPN::execRpn(std::string toCalculate) {
	if (!this->isValidInput(toCalculate))
		throw std::runtime_error("Error");
	std::istringstream iss(toCalculate);
	std::string value;
	int number;
	int nb1, nb2;
	std::stack<int> myStack;
	while (iss >> value) {
		if (this->isNumber(value)) {
			number = this->myStdtoi(value);
			myStack.push(number);
		} else if (this->isOperator(value[0])) {
			if (myStack.size() < 2)
				throw std::runtime_error("Error");
			nb1 = myStack.top();
			myStack.pop();
			nb2 = myStack.top();
			myStack.pop();
			number = this->calculate(nb2, nb1, value);
			myStack.push(number);
		} else {
			throw std::runtime_error("Error");
		}
	}
	std::cout << myStack.top() << std::endl;
}