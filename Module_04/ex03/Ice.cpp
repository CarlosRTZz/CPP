#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {

}

Ice::Ice(const Ice &copy) : AMateria(copy){

}

Ice::~Ice(void) {

}

Ice &Ice::operator=(const Ice &rhs) {
	this->_type = rhs._type;
	return (*this);
}

AMateria *Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}