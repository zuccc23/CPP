#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl << "===== Making objects =====" << std::endl ;
	try
	{
		Bureaucrat buro("mina", 1);
		std::cout << std::endl << "===== Tests =====" << std::endl ;
		std::cout << buro;
		std::cout << ++buro;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== Making objects =====" << std::endl ;
	try
	{
		Bureaucrat buro2("pompom", 150);
		std::cout << std::endl << "===== Tests =====" << std::endl ;
		std::cout << buro2;
		std::cout << --buro2;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return(0);
}