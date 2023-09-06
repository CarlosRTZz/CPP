#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private :
		std::string _name;
		AMateria *_inventory[4];

	public :
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

		Character &operator=(const Character &rhs);

		Character(void);
		Character(std::string const &name);
		Character(Character const &copy);
		~Character(void);
};

#endif