#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) {
	this->type = copy.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << this->type << ": MEOW MEOW MEOW MEOWWWWWWWW MEEEEEEOOOOOWWWWW !!!!!! (Yes cats are boring!)" << std::endl;
}
