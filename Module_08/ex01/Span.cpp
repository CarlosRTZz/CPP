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
	this->_vectorN.push_back(N);
}

void Span::addNumber(std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite) {
	unsigned int distance = std::distance(it, ite);
	if ((this->_vectorN.size() + distance) > this->_N) {
		throw Span::vectorOTB();
	}
	this->_vectorN.insert(this->_vectorN.end(), it, ite);
}

unsigned int Span::shortestSpan(void) {
	if (this->_vectorN.size() <= 1) {
		throw Span::onlyOneNb();
	}
	std::vector<int> sorted = this->_vectorN;
	std::sort(sorted.begin(), sorted.end());
	unsigned int distanceMin = sorted[1] - sorted[0];
	for (std::vector<int>::size_type i = 0; (i + 1) < sorted.size(); i++) {
		unsigned int distance = sorted[i + 1] - sorted[i];
		if (distance < distanceMin) {
			distanceMin = distance;
		}
	}
	return (distanceMin);
}

unsigned int Span::longestSpan(void) {
	if (this->_vectorN.size() <= 1) {
		throw Span::onlyOneNb();
	}
	std::vector<int> sorted = this->_vectorN;
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size() - 1] - sorted[0]);
}
