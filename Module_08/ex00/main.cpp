#include "easyfind.hpp"

int main (void) {
	std::vector<int> monVecteur;
    for (int i = 1; i <= 5; ++i) {
        monVecteur.push_back(i);
    }

	easyfind(monVecteur, 8);
}