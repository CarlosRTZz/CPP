#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private :
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
	
	public :
		AForm(const std::string name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm &copy);
		virtual ~AForm(void);

		AForm &operator=(const AForm &rhs);

		std::string getName(void) const;
		bool		getSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const; 
		void		beSigned(const Bureaucrat bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Grade too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Grade too low!");
				}
		};

		class NotSignedException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Form not signed!!!");
				}
		};
};

std::ostream &operator<<(std::ostream & o, const AForm &fixed);

#endif