#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include <Weapon.hpp>

class HumanB {
	private :
		std::string _name;
		Weapon *_weapon;

	public :
		std::string getName(void);
		void setName(std::string name);
		void attack(void);
		void setWeapon(Weapon &club);

		HumanB(std::string name);
		~HumanB();
};

#endif