#include "Intern.hpp"

Intern::Intern(void) {

}

Intern::~Intern(void) {

}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern &Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string targetName) {
	std::string formList [] = {
		"Presidential pardon", "Robotomy request", "Shrubbery creation"
	};

	AForm*    forms[] = {
    new RobotomyRequestForm( targetName ),
    new PresidentialPardonForm( targetName ),
	new ShrubberyCreationForm( targetName )
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formList[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i]);
		}
	}
	throw Intern::unknownForm();
}