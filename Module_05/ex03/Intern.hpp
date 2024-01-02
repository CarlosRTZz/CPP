#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public :
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern &operator=(const Intern &rhs);

		AForm* makeForm(std::string formName, std::string targetName);
};

#endif