#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{

	std::cout << "\033[1;31m" << "[ PDF TEST ]" << "\033[0m" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	std::cout << "\033[1;33m" << "[ MY TEST ]" << "\033[0m" << std::endl;
	IMateriaSource* magic = new MateriaSource();
	magic->learnMateria(new Ice());
	magic->learnMateria(new Cure());

	ICharacter *fluchten = new Character("fluchten");
	AMateria* temp;
	temp = magic->createMateria("ice");
	fluchten->equip(temp);
	temp = magic->createMateria("cure");
	fluchten->equip(temp);
	temp = magic->createMateria("ice");
	fluchten->equip(temp);
	temp = magic->createMateria("cure");
	fluchten->equip(temp);

	ICharacter* cortiz = new Character("cortiz");

	fluchten->use(0, *cortiz);
	fluchten->use(1, *cortiz);
	fluchten->use(2, *cortiz);
	fluchten->use(3, *cortiz);

	std::cout << std::endl;

	fluchten->unequip(0);
	fluchten->unequip(5);
	fluchten->unequip(-5);
	fluchten->unequip(1);

	std::cout << std::endl;

	fluchten->use(0, *cortiz);
	fluchten->use(1, *cortiz);
	fluchten->use(2, *cortiz);
	fluchten->use(3, *cortiz);
	fluchten->use(4, *cortiz);
	fluchten->use(-3, *cortiz);

	delete cortiz;
	delete magic;
	delete fluchten;

	return 0;
}