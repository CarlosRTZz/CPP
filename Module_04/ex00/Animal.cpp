# include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = copy.type;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	this->type = rhs.type;
	std::cout << "Animal Assignation operator called" << std::endl;
	return (*this);
}

void Animal::makeSound(void) const {
	std::cout << this->type << ": ..." << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
}
