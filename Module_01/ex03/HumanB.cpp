#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {

}

HumanB::~HumanB(void) {

}

void HumanB::setWeapon(Weapon &club) {
	this->_weapon = &club;
}

void HumanB::attack(void) {
	std::cout << this->_name << "  attacks with their " << this->_weapon->getType() << std::endl;
}