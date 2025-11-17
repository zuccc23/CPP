#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::cout << std::endl << "===== test =====" << std::endl ;
	BitcoinExchange btc;
	std::string filename = av[1];
	try
	{
		btc.fillDatabase("data.csv");
		btc.processInputValues(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}