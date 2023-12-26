#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private : 
		std::string _target;

	public : 
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &presidential);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

		virtual void execute(Bureaucrat &executor) const;
};

#endif