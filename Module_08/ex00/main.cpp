#include "easyfind.hpp"

int main (void) {
	std::vector<int> myVector;
    for (int i = 1; i <= 5; ++i) {
        myVector.push_back(i);
    }

	std::list<int> myList;
	for (int i = 1; i <= 5; ++i)
	{
		myList.push_back(i);
	}

	easyfind(myVector, 1);
	easyfind(myList, 3);
}