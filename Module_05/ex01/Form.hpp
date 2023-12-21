#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
	
	public :
		Form(const std::string name, const int gradeToSign, const int gradeToExec);
		Form(const Form &copy);
		~Form(void);

		Form &operator=(const Form &rhs);

		std::string getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;
		void		beSigned(const Bureaucrat bureaucrat);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form grade too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form grade too low!");
				}
		};
};

std::ostream &operator<<(std::ostream & o, const Form &fixed);

#endif