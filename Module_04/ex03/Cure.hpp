#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public :
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

		Cure &operator=(const Cure &rhs);

		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);
};

#endif