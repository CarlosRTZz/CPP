#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public :
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

		Ice &operator=(const Ice &rhs);

		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);
};

#endif