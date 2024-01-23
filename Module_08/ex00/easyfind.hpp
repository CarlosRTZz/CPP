#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

template <typename T>
void easyfind(const T &container, int i) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), i);
	
	if (it != container.end()) {
        std::cout << "Value " << *it << " was found in index " << std::distance(container.begin(), it) << std::endl;
    } else {
        std::cout << "Value " << i << " was not found" << std::endl;
    }
}

#endif