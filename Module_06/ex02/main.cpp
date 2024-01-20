#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "iostream"
#include <cstdlib>
#include <ctime>

Base* generate(void) {
	int nbr;

	srand(time(0));
	nbr = rand() % 3 + 1;
	switch (nbr) {
		case (1):
			return (new A);
		case (2):
			return (new B);
		case (3):
			return (new C);
	}
}

void identify(Base *p) {
	A* derivedA = dynamic_cast<A*>(p);
	if (derivedA)
		std::cout << "A" << std::endl;
	B* derivedB = dynamic_cast<B*>(p);
	if (derivedB)
		std::cout << "B" << std::endl;
	C* derivedC = dynamic_cast<C*>(p);
	if (derivedC)
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast &e){

	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	} catch (const std::bad_cast &e) {

	}

	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	} catch (const std::bad_cast &e) {

	}
}

int	main(void)
{
	std::cout << "[ BASE A ]" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;
	std::cout << std::endl;

	std::cout << "[ BASE B ]" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;
	std::cout << std::endl;

	std::cout << "[ BASE C ]" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;
	std::cout << std::endl;

	std::cout << "[ BASE RANDOM ]" << std::endl;
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;

	return (0);
}
