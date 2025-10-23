#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		std::cout << std::endl << "===== ShrubberyCreationForm Tests =====" << std::endl ;
		Bureaucrat buro("Buro", 13);
		ShrubberyCreationForm formi("Formi");

		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== RobotomyRequestForm Tests =====" << std::endl ;
		Bureaucrat buro("Buro", 13);
		RobotomyRequestForm formi("Formi");

		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl << "===== PresidentialPardonForm Tests =====" << std::endl ;
		Bureaucrat buro("Buro", 1);
		PresidentialPardonForm formi("Formi");

		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== Bureaucrat Tests =====" << std::endl ;
		Bureaucrat buro("Buro", 140);
		ShrubberyCreationForm formi("Shrub");

		buro.signForm(formi);
		buro.executeForm(formi);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	return(0);
}