#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span {
	private :
		unsigned int _N;
		std::vector<int> _vectorN;
	public :
		Span(unsigned int N);
		Span(const Span &copy);
		~Span(void);

		Span &operator=(const Span &rhs);

		void addNumber(unsigned int N);
		void addNumber(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		class vectorOTB : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("You have exceeded the maximum size in the span!");
				}
		};

		class onlyOneNb : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("To less numbers do find shortest Span!");
				}
		};
};

#endif