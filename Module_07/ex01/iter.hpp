#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, std::size_t size, void (*function)(T const &)) {
	for (std::size_t i = 0; i < size; i++) {
		//std::cout << "Value " << i << " = ";
		function(array[i]);
	}
}



#endif