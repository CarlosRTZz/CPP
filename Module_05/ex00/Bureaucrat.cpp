#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
}

int Bureaucrat::getGrade(void) const {
	return this->_grade;
}

std::string Bureaucrat::getName(void) const {
	return this->_name;
}

void Bureaucrat::incrementBureaucrat(void) {
	if (this->getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementBureaucrat(void) {
	if (this->getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream & o, const Bureaucrat &bureaucrat) {
	o << bureaucrat.getName() << (", bureaucrat grade ") << bureaucrat.getGrade();
	return o;
}