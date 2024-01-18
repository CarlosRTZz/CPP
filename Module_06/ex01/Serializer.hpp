#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer {
	public:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &copy);

		Serializer &operator=(const Serializer &rhs);
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private :
};

#endif