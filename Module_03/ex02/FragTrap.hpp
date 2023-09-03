#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ScavTrap {
	private :

	public :
		void highFivesGuys(void);

		FragTrap &operator=(const FragTrap &rhs);

		FragTrap(void);
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &copy);
		~FragTrap(void);
};

#endif