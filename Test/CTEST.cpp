#include <stdio.h>

int	gl_var = 1;
int	f(void) {return 2; }

namespace	trois {
	int gl_var = 3;
	int	f( void ) {return 4; }
}

namespace	cinq {
	int gl_var = 5;
	int f( void ) {return 6; }
}

namespace Muf = cinq;

// int main ( void ) {
// 	printf("gl_var;	%d\n", gl_var);
// 	printf("f();	%d\n\n", f());

// 	printf("trois::gl_var;	%d\n", trois::gl_var);
// 	printf("trois::f();	%d\n\n", trois::f());

// 	printf("cinq::gl_var;	%d\n", cinq::gl_var);
// 	printf("cinq::f();	%d\n\n", cinq::f());

// 	printf("gl_var;	%d\n", gl_var);
// 	printf("f();	%d\n\n", f());

// 	return 0;
// }

#include <iostream>
int main ( void )
{
	char	buff[0];

	std::cout << "Hello world !" << std::endl;

	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;

	return 0;
}