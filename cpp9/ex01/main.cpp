#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: one argument is expected (put your input inside quotes)" << std::endl;
		return (1);
	}
	
	RPN rpn;

	try
	{
		std::cout << rpn.calculate(av[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	
	return 0;
}