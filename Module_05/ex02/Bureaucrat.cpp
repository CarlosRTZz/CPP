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

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " can't execute " << form.getName() << " cause " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream & o, const Bureaucrat &bureaucrat) {
	o << bureaucrat.getName() << (", bureaucrat grade ") << bureaucrat.getGrade();
	return o;
}