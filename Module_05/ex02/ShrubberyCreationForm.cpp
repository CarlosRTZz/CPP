#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &shrubbery) : AForm(shrubbery), _target(shrubbery._target){

}

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::execute(Bureaucrat &executor) const {
	if (!this->_signed)
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->getGrade());
		throw (AForm::GradeTooLowException());

	std::ofstream file(this->_target + _shrubbery);
	if (file.is_open())
	{
		file << "ASCII TREES" << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Failed to create file!" << std::endl;
		return ;
	}
}