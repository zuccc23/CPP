#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl << "===== Right grade Test =====" << std::endl ;
		Bureaucrat buro("Mina", 50);
		Form formi("Contract", 100, 51);

		std::cout << buro;
		std::cout << formi;

		buro.signForm(formi);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== Wrong grade Test =====" << std::endl ;
		Bureaucrat buro("Mina", 140);
		Form formi("Contract", 100, 51);
		std::cout << buro;
		std::cout << formi;

		buro.signForm(formi);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== beSigned(form) Test =====" << std::endl ;
		Bureaucrat buro("Mina", 140);
		Form formi("Contract", 150, 51);
		std::cout << buro;
		std::cout << formi;

		formi.beSigned(buro);
		std::cout << formi;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== beSigned(form) FAILED Test =====" << std::endl ;
		Bureaucrat buro("Mina", 140);
		Form formi("Contract", 100, 51);
		std::cout << buro;
		std::cout << formi;

		formi.beSigned(buro);
		std::cout << formi;
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	return(0);
}