#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <time.h>
#include <iomanip>
#include <sstream>

class PmergeMe {
	private :
		bool _isInt(char* stsr);
	public :
		void checkInput(int ac, char** av);
		PmergeMe(void);
		PmergeMe(const PmergeMe & copy);
		~PmergeMe(void);
		PmergeMe&operator=(const PmergeMe & rhs);
};

#endif