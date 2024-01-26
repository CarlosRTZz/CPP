#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {

}

Span::Span(const Span &copy) {
	*this = copy;
}

Span::~Span(void) {

}

Span &Span::operator=(const Span &rhs) {
	this->_N = rhs._N;
	this->_vectorN = rhs._vectorN;
	return (*this);
}

void Span::addNumber(unsigned int N) {
	if (this->_vectorN.size() >= this->_N) {
		throw Span::vectorOTB();
	}
	this->_vectorN.pushBack(N);
}

void Span::shortestSpan(void) {
	if (this->_vectorN.size() <= 1) {
		throw Span::onlyOneNb();
	}
}