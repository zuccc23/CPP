#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Fixed.hpp"

int	main(void)
{

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	if (a > b)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	return (0);
}