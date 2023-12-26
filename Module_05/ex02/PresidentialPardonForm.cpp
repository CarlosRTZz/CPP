#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &presidential) : AForm(presidential), _target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm(void) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	Aform::operator=(rhs);
	this->_target = rhs._target;
	return(*this);
}

PresidentialPardonForm::execute(Bureaucrat &executor) const {
	if (!this->_signed)
		throw(AForm::NotSignedException());
	if (executor.getGrade > this->gradeToExec)
		throw (AForm::GradeTooLowException());
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox <3" << std::endl;
}