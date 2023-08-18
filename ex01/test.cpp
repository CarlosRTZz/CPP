#include "test.hpp"

Sample::Sample(void) {
	std::cout << "Constructor Called" << std::endl;
	return ;
}

Sample::~Sample(void) {
	std::cout << "Destructor Called" << std::endl;
	return ;
}

int main(void)
{
	Sample salut;
}