#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("IDK") {
	std::cout << "Bureaucrat construcot called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat 
std::exeption;