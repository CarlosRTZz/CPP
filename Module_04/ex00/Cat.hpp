#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public :
		void makeSound(void);

		Cat &operator=(const Cat &rhs);

		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);
};

#endif