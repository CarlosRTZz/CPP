#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		void makeSound(void) const;

		WrongCat &operator=(const WrongCat &rhs);

		WrongCat(void);
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat(void);
};

#endif