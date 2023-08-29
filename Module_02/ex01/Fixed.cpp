#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->_bit;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->_bit));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = fixed.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << this->_bit);
}

int Fixed::toInt(void) const {
	return (this->value >> this->_bit);
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

std::ostream &operator<<(std::ostream & o, const Fixed &fixed) {
	o << fixed.toFloat();
	return o;
}
