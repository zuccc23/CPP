
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "whatever.hpp"

int main (void)
{
	std::cout << std::endl << "===== Swap =====" << std::endl ;
	int x = 1;
	int y = 2;
	std::cout << "x: " << x << " y: " << y << std::endl;
	swap(x, y);
	std::cout << "x: " << x << " y: " << y << std::endl;

	std::cout << std::endl << "===== Min & Max =====" << std::endl ;
	std::string first = "apple";
	std::string second = "banana";
	std::cout << "first string: " << first << " second string: " << second << std::endl <<  "lexicographical order: " << min(first, second) << " " << max(first, second) << std::endl;

	std::cout << std::endl << "===== Subject tests =====" << std::endl ;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}