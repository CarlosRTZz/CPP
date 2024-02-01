#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public :
		MutantStack<T>(void) : std::stack<T>() {}
		MutantStack<T>(const MutantStack &copy) : std::stack<T>(copy) {}
		MutantStack &operator=(const MutantStack &rhs) {(void) rhs; return (*this);}
		~MutantStack(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {return (this->c.begin());}
		iterator end(void) {return (this->c.end());}
};

#endif