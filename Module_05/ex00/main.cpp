#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat John("John", 100);
		std::cout << John << std::endl;

		John.incrementBureaucrat();
		std::cout << John << std::endl;

		John.decrementBureaucrat();
		std::cout << John << std::endl;

		Bureaucrat Alice("Alice", 1);
		std::cout << Alice << std::endl;

		Alice.incrementBureaucrat(); // Throws GradeTooHighException
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat Bob("Bob", 150);
		std::cout << Bob << std::endl;

		Bob.decrementBureaucrat();
		std::cout << Bob << std::endl;

		Bob.incrementBureaucrat();
		Bob.incrementBureaucrat(); // Throws GradeTooLowException
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat fluchten("fluchten", 250);
		std::cout << fluchten << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}