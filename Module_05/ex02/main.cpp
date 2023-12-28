#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 1 ~~~" << "\033[0m" << std::endl;
		
		Bureaucrat fluchten("Fluchten", 55);

		ShrubberyCreationForm f1("fluchten");
		RobotomyRequestForm f2("fluchten");
		PresidentialPardonForm f3("fluchten");

		std::cout << fluchten << std::endl << f1 << std::endl << f2 << std::endl << f3 << std::endl;

		fluchten.signForm(f1);
		fluchten.signForm(f2);
		fluchten.signForm(f3);
		
		fluchten.executeForm(f1);
		fluchten.executeForm(f2);
		fluchten.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 2 ~~~" << "\033[0m" << std::endl;
		
		Bureaucrat cortiz("cortiz", 1);

		ShrubberyCreationForm f1("cortiz");
		RobotomyRequestForm f2("cortiz");
		PresidentialPardonForm f3("cortiz");

		std::cout << cortiz << std::endl << f1 << std::endl << f2 << std::endl << f3 << std::endl;

		cortiz.signForm(f1);
		cortiz.signForm(f2);
		cortiz.signForm(f3);
		
		cortiz.executeForm(f1);
		cortiz.executeForm(f2);
		cortiz.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "\033[1;32m" << "~~~ TEST 2 ~~~" << "\033[0m" << std::endl;
		
		Bureaucrat cortiz("cortiz", 120);

		ShrubberyCreationForm f1("cortiz");
		RobotomyRequestForm f2("cortiz");
		PresidentialPardonForm f3("cortiz");

		std::cout << cortiz << std::endl << f1 << std::endl << f2 << std::endl << f3 << std::endl;

		cortiz.signForm(f1);
		cortiz.signForm(f2);
		cortiz.signForm(f3);
		
		cortiz.executeForm(f1);
		cortiz.executeForm(f2);
		cortiz.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}