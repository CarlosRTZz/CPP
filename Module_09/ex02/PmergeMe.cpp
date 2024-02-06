#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {

}

PmergeMe::PmergeMe(const PmergeMe & copy) {
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe & rhs) {
	(void)rhs;
	return (*this);
}

PmergeMe::~PmergeMe(void) {

}

bool PmergeMe::_isInt(char *str)
{
	int i = 0;

	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void PmergeMe::checkInput(int ac, char** av) {
	for (int i = 1; i < ac; i++) {
		if (this->_isInt(av[i]) == false) {
			throw (std::runtime_error("Error"));
		}
		std::istringstream iss(av[i]);
		int number;
		iss >> number;
		if (iss.fail()) {
			throw (std::runtime_error("Error"));
		}
	}
}