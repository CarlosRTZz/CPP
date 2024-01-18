#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &rhs) {
	(void) rhs;
	return (*this);
}

Serializer::Serializer(const Serializer &copy) {
	*this = copy;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}