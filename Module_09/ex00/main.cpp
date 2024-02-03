#include "BitcoinExchange.hpp"

int main (int ac, char** av) {
	if (ac == 2) {
		try {
			BitcoinExchange salut;
			salut.execExchange(av[1]);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}
}