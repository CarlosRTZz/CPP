#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : 
	_name(name), 
	_signed(false), 
	_gradeToSign(gradeToSign), 
	_gradeToExec(gradeToExec)
{
	if (gradeToExec < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : 
	_name(copy._name), 
	_signed(copy._signed), 
	_gradeToSign(copy._gradeToSign), 
	_gradeToExec(copy._gradeToExec)
{

}

Form::~Form(void) {}

Form &Form::operator=(const Form &rhs) {
	this->_signed = rhs._signed;
	return (*this);
}

std::string Form::getName(void) const {
	return (this->_name);
}

bool Form::getSigned(void) const {
	return (this->_signed);
}

int	Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

int Form::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

void Form::beSigned(const Bureaucrat bureaucrat) {
	if (bureaucrat.getGrade() > getGradeToSign())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream & o, const Form &form) {
	o << "Form name : " << form.getName() << std::endl
	<< "Form grade to execute : " << form.getGradeToExec() << std::endl
	<< "Form grade to sign : " << form.getGradeToSign();
	return o;
}