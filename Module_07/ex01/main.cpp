#include "iter.hpp"

template <typename T>
void print(T const & toPrint) {
	std::cout << toPrint << std::endl;
}

int main (void) {
	int array[3] = {45, 67, 98};
	char array2[3] = {'a', 'b', 'c'};
	std::string array3[3] = {"AHHH", "OHHH", "IHHH"};

	iter(array, 3, print);
	std::cout << std::endl;
	iter(array2, 3, print);
	std::cout << std::endl;
	iter(array3, 3, print);
}