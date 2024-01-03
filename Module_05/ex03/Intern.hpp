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

		class unknownForm : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form passed as parameter is unknown");
				}
		};
};

#endif