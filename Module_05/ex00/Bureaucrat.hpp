#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private :
		const std::string	_name;
		int					_grade;

	public :
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void	incrementBureaucrat();
		void	decrementBureaucrat();

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
};

std::ostream &operator<<(std::ostream & o, const Bureaucrat &fixed);

#endif