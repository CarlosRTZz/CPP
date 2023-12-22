#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private : 
		std::string _target;

	public :
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(RobotomyRequestForm &robotomy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};

#endif