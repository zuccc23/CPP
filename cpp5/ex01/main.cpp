#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << "===== Making objects =====" << std::endl ;
	try
	{
		Bureaucrat buro("Mina", 50);
		Form formi("Contract", 100, 51);

		std::cout << std::endl << "===== Tests =====" << std::endl ;
		std::cout << formi;

		// formi.beSigned(buro);
		// std::cout << formi;

		buro.signForm(formi);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	// std::cout << std::endl << "===== Making objects =====" << std::endl ;
	// try
	// {
	// 	// Bureaucrat buro2("pompom", 150);
	// 	std::cout << std::endl << "===== Tests =====" << std::endl ;
	// 	// std::cout << buro2;
	// 	// std::cout << --buro2;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "Caught: " << e.what() << std::endl;
	// }
	
	return(0);
}