#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private :
		const std::string	_name;
		int					_grade;

	public :
		std::string	getName(void) const;
		int			getGrade(void) const;

		void	increment(const Bureaucrat);
		void	decrement(const Bureaucrat);

		Bureaucrat &operator=(const Bureaucrat &rhs);

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);
};

#endif