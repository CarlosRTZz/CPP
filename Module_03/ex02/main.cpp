#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap cortiz("Cortiz");
	FragTrap francois("francois");
	FragTrap marwane("Marwane");

	std::cout << std::endl;
    std::cout << "\033[1;30m" << " Test 1 ~ ATTACK ~ " << "\033[0m" << std::endl;
	cortiz.attack("francois");
	cortiz.attack("Marwane");
	std::cout << std::endl;

    std::cout << "\033[1;31m" << " Test 2 ~ TAKE DAMAGE ~ " << "\033[0m" << std::endl;
	francois.takeDamage(85);
	francois.takeDamage(15);
	francois.takeDamage(1);
	francois.takeDamage(2);
	francois.takeDamage(3);
	marwane.takeDamage(25);
	std::cout << std::endl;

    std::cout << "\033[1;32m" << "Test 3 ~ BE REPAIRED ~ " << "\033[0m" << std::endl;
	cortiz.beRepaired(3);
	francois.beRepaired(8);
	marwane.beRepaired(2);
	marwane.beRepaired(5);
	std::cout << std::endl;

    std::cout << "\033[1;34m" << "Test 4 ~ HIGH FIVES GUYS ~ " << "\033[0m" << std::endl;
	cortiz.highFivesGuys();
	francois.highFivesGuys();
	marwane.highFivesGuys();
	std::cout << std::endl;

    return (0);
}