#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	*this = copy;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs) {
	this->_type = rhs._type;
	std::cout << "AMateria assignement operator called" << std::endl;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* " << this->_type << " used on " << target.getName() << " *" << std::endl;
}
