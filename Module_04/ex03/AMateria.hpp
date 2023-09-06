#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public :
		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria &operator=(const AMateria &rhs);

		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria(void);
};

#endif