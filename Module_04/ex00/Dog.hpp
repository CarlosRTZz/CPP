#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public :
		void makeSound(void);

		Dog &operator=(const Dog &rhs);

		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);
};

#endif