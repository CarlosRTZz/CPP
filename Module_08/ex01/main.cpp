#include "Span.cpp"

int main()
{
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Span sp = Span(3);

		sp.addNumber(32);
		sp.addNumber(2);
		sp.addNumber(76);
		sp.addNumber(36);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Span sp(50000);
		std::vector<int> idk;
		std::srand(std::time(NULL));
		for (int i = 0; i < 50000; i++) {
			idk.push_back(std::rand());
		}
		sp.addNumber(idk.begin(), idk.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}