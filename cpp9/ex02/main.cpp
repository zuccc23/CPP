#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cerr << "Error: too few arguments to sort" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe merge;
		merge.sort(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}