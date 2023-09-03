#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ScavTrap() {
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap \"" << this->_name << "\" constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ScavTrap(name) {
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap \"" << this->_name << "\" constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ScavTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
	std::cout << "FragTrap Assignation operator called" << std::endl;
	ScavTrap::operator=(rhs);
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (hitPoint > 0)
		std::cout << "High Five?" << std::endl;
	else 
		std::cout << "FragTrap \"" << this->_name << "\" is dead!" << std::endl;
}