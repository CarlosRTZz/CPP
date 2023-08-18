#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; av[i]; i++)
	{
		std::string str = av[i];
		for (int j = 0; str[j]; j++)
		{
			std::cout << (char)std::toupper(str[j]);
		}
		std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}