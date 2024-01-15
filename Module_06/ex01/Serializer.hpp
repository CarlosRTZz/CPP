#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer {
	public:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &copy);

		Serializer &operator=(const Serializer &rhs);
	
	private :
		static uintptr_t serialize(Data* ptr);
};

#endif