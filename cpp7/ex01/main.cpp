
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "iter.hpp"

void	printStr(std::string const& str)
{
	std::cout << str << std::endl;
}

void	printInt(int const& num)
{
	std::cout << num << std::endl;
}

void	incrementInt(int& num)
{
	num++;
}

int main (void)
{
	std::cout << std::endl << "===== Iter on print Str =====" << std::endl ;
	std::string strArray[5] = {"hello", "this", "is", "a", "test"};
	iter(strArray, 5, printStr);

	std::cout << std::endl << "===== Iter on print Int =====" << std::endl ;
	int	intArray[6] = {1, 2, 3, 4, 5, 6};
	iter(intArray, 6, printInt);

	std::cout << std::endl << "===== Iter on increment Int =====" << std::endl ;
	iter(intArray, 6, incrementInt);
	iter(intArray, 6, printInt);
	
	return 0;
}