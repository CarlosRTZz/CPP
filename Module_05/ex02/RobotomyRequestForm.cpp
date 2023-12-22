#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &robotomy) : AForm(robotomy), _target(robotomy._target){

}

RobotomyRequestForm::~RobotomyRequestForm(void) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	this->_target = rhs._target;
	return(*this);
}