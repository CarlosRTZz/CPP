#include "Zombie.hpp"

int main(int ac, char **av)
{
	std::string name = av[1];
	Zombie* zombie(name);
}