#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) {
	this->type = copy.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const{
	std::cout << this->type << ": Bark bark (Dogs are the best !!!)" << std::endl;
}