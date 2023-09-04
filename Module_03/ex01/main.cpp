#include "ScavTrap.hpp"

int main(void)
{
 	ScavTrap cortiz("Cortiz");
	ScavTrap murillo("Murillo");
	ScavTrap marwane("Marwane");

	std::cout << std::endl;
    std::cout << "\033[1;30m" << " Test 1 ~ ATTACK ~ " << "\033[0m" << std::endl;
	cortiz.attack("Murillo");
	cortiz.attack("Marwane");
	marwane.attack("Cortiz");
	marwane.attack("Monster");
	std::cout << std::endl;

    std::cout << "\033[1;31m" << " Test 2 ~ TAKE DAMAGE ~ " << "\033[0m" << std::endl;
	murillo.takeDamage(85);
	murillo.takeDamage(15);
	murillo.takeDamage(1);
	murillo.takeDamage(2);
	murillo.takeDamage(3);
	marwane.takeDamage(25);
	std::cout << std::endl;

    std::cout << "\033[1;32m" << "Test 3 ~ BE REPAIRED ~ " << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	murillo.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

    std::cout << "\033[1;36m" << "Test 4 ~ GUARD GATE ~ " << "\033[0m" << std::endl;
	cortiz.guardGate();
	murillo.guardGate();
	marwane.guardGate();
	std::cout << std::endl;

    return (0);
}