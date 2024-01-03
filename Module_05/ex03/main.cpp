/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 08:09:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2024/01/03 14:25:13 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 1 ~~~" << "\033[0m" << std::endl;
		Intern fluchten;
		Bureaucrat cortiz("carlos", 2);
		AForm *f1 = fluchten.makeForm("Robotomy request", "cortiz");

		cortiz.signForm(*f1);
		cortiz.executeForm(*f1);
		delete f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 2 ~~~" << "\033[0m" << std::endl;
		Intern fluchten;
		Bureaucrat cortiz("carlos", 2);
		AForm *f1 = fluchten.makeForm("Shrubbery creatiOn", "baadform");

		cortiz.signForm(*f1);
		cortiz.executeForm(*f1);
		delete f1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}