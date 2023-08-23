#include "Zombie.hpp"

Zombie::Zombie(std::string name) : Name(name) {
	
}

Zombie::~Zombie() {
	std::cout << this->Name << " is destroyed ¯\\_(ツ)_/¯" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
