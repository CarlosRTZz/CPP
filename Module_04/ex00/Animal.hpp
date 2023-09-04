#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	protected :
		std::string type;

	public :
		

		Animal(void);
		Animal(const Animal &copy);
		virtual ~Animal(void);
};

#endif