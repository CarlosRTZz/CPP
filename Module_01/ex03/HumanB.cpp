#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) , _weapon(NULL){

}

HumanB::~HumanB() {

}

std::string HumanB::getName() {
	return this->_name;
}

void HumanB::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &club) {
	this->_weapon = &club;
}
