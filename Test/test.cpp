#include "test.hpp"
#include <iostream>

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
	return ;
}

void	Sample::bar(void) {
	std::cout << "Function bar called" << std::endl;
	return ;
}
