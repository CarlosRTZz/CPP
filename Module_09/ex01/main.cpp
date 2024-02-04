#include "RPN.hpp"

int main (int ac, char** av) {
	if (ac == 2) {
		try
		{
			std::string toCalculate = av[1];
			RPN rpn;
			rpn.execRpn(toCalculate);
			return (0);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
	}
	std::cout << "Error" << std::endl;
	return (1);
}