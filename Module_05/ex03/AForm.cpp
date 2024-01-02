#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : 
	_name(name), 
	_signed(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : 
	_name(copy._name), 
	_signed(copy._signed), 
	_gradeToSign(copy._gradeToSign), 
	_gradeToExec(copy._gradeToExec)
{

}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &rhs) {
	this->_signed = rhs._signed;
	return (*this);
}

std::string AForm::getName(void) const {
	return (this->_name);
}

bool AForm::getSigned(void) const {
	return (this->_signed);
}

int	AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

void AForm::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream & o, const AForm &Aform) {
	o << "Form name : " << Aform.getName() << std::endl
	<< "Form grade to execute : " << Aform.getGradeToExec() << std::endl
	<< "Form grade to sign : " << Aform.getGradeToSign();
	return o;
}