#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &presidential) : AForm(presidential), _target(presidential._target) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw(AForm::NotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException());
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox <3" << std::endl;
}