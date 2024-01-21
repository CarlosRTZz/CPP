#include <iostream>
#include <ctime>
#include "Array.hpp"

template <typename T>
void printArray(Array <T>array) {
	for (unsigned int i = 0; i < array.size(); i++) {
		if (i != 0)
			std::cout << " | ";
		std::cout << array[i];
	}
	std::cout << std::endl << std::endl;
}

int main (void) {
	srand(time(0));
	unsigned int size = 5;
	Array<int> array1(size);
	for (unsigned int i = 0; i < size; i++) {
		array1[i] = rand() % 10 + 1;
	}
	std::cout << "----Array1----" << std::endl;
	printArray(array1);

	Array<int> assignArray = array1;
	std::cout << "----assignArray----" << std::endl;
	printArray(assignArray);

	Array<int> copyOperatorArray(array1);
	std::cout << "----copyOperatorArray----" << std::endl;
	printArray(copyOperatorArray);

	try {
		std::cout << array1[-2] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << array1[5] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << array1[3] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}





	std::cout << std::endl << std::endl << "\033[32m" << "NOW THE SAME BUT WITH CHAR" << "\033[0m" << std::endl << std::endl;





	Array<char> CharArray1(5);
	CharArray1[0] = 'a';
	CharArray1[1] = 'b';
	CharArray1[2] = 'c';
	CharArray1[3] = 'd';
	CharArray1[4] = 'e';

	std::cout << "----CharArray1----" << std::endl;
	printArray(CharArray1);

	Array<char> CharAssignArray = CharArray1;
	std::cout << "----CharAssignArray----" << std::endl;
	printArray(CharAssignArray);

	Array<char> CharCopyOperatorArray(CharArray1);
	std::cout << "----CharCopyOperatorArray----" << std::endl;
	printArray(CharCopyOperatorArray);

	try {
		std::cout << CharArray1[-2] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << CharArray1[5] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << CharArray1[3] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}