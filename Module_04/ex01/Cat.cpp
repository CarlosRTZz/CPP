#include "Cat.hpp"

Cat::Cat(void) {
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) {
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	this->type = rhs.type;
	this->brain = rhs.brain;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << this->type << ": MEOW MEOW MEOW MEOWWWWWWWW MEEEEEEOOOOOWWWWW !!!!!! (Yes cats are boring!)" << std::endl;
}
