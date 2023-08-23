#include "Zombie.hpp"

Zombie::Zombie(std::string name) : Name(name) {

}

Zombie::~Zombie() {

}

void	Zombie::announce(void) {
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
