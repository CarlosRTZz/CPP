#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	this->type = copy.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << this->type << ": MEOW MEOW MEOW MEOWWWWWWWW MEEEEEEOOOOOWWWWW !!!!!! (Yes WrongCats are boring!)" << std::endl;
}