
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "ScalarConverter.hpp"
#include "utils.hpp"

int main (int ac, char **av)
{
	std::string input;

	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: wrong argument amount" << std::endl;
		return (1);
	}
	input = av[1];
	
	ScalarConverter::convert(input);
	return(0);
}