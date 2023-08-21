#include "PhoneBook.hpp"

int main()
{
	PhoneBook repertoire;
	std::string str;
	
	while (str != "EXIT")
	{
		std::cout << "[Type a command]" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (str == "ADD")
			repertoire.add();
		if (str == "SEARCH")
			repertoire.search();
	}
	return 0;
}