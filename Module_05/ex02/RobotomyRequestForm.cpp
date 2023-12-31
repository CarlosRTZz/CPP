#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &robotomy) : AForm(robotomy), _target(robotomy._target){

}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	AForm::operator=(rhs);
	this->_target = rhs._target;
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException());
	srand(time(0));
	if ((rand() % 100) < 50)
		std::cout << "The robotomy failed !" << std::endl;
	else 
		std::cout << this->_target << " has been robotomized :D" << std::endl;
}
