#include "ClapTrap.hpp"

int main (void) {
	ClapTrap one;
	ClapTrap two("two");
	ClapTrap three("three");
	ClapTrap twoCopy = two;

	one.takeDamage(8);
	one.takeDamage(5);
	one.takeDamage(1);
}