#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal {
	protected :
		std::string type;

	public :
		virtual void makeSound(void) const;
		std::string getType(void) const;

		Animal &operator=(const Animal &rhs);

		Animal(void);
		Animal(const Animal &copy);
		virtual ~Animal(void);
};

#endif