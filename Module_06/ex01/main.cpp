#include "Serializer.hpp"

int main (void) {
	Data myData;

	myData.myVar = "ahaahahhaaaah";

	uintptr_t serialized = Serializer::serialize(&myData);

	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "The real one : " << myData.myVar << std::endl;
	std::cout << "The serialized one : " << deserialized->myVar << std::endl;
}