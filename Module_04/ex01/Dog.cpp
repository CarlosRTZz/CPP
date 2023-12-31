#include "Dog.hpp"

Dog::Dog(void) {
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
	this->type = copy.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	this->type = rhs.type;
	this->brain = rhs.brain;
	std::cout << "Dog Assignation operator called" << std::endl;
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << this->type << ": Bark bark (Dogs are the best !!!)" << std::endl;
}