#include "Zombie.hpp"

Zombie::Zombie(void) : Name("(unknown)") {
	std::cout << "Zombie " << this->Name << " has been created" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : Name(name) {
	std::cout << "Zombie " << this->Name << " has been created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->Name << " is destroyed ¯\\_(ツ)_/¯" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(std::string name) {
	this->Name = name;
}
