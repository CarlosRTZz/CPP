#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
void easyfind(T &container, int i) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), i);
	
	if (it != container.end()) {
        std::cout << "La valeur " << *it << " a été trouvée a la distance " << std::distance(container.begin(), it) << std::endl;
    } else {
        std::cout << "La valeur " << i << " n'a pas été trouvée dans le vecteur." << std::endl;
    }
}

#endif