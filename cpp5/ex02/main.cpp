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
		std::cout << std::endl << "===== Making objects =====" << std::endl ;
		Bureaucrat buro("Mina", 13);
		ShrubberyCreationForm formi("idk");

		std::cout << std::endl << "===== ShrubberyCreationForm Tests =====" << std::endl ;
		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== Making objects =====" << std::endl ;
		Bureaucrat buro("Mina", 13);
		RobotomyRequestForm formi("idk");

		std::cout << std::endl << "===== RobotomyRequestForm Tests =====" << std::endl ;
		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << std::endl << "===== Making objects =====" << std::endl ;
		Bureaucrat buro("Mina", 1);
		PresidentialPardonForm formi("idk");

		std::cout << std::endl << "===== PresidentialPardonForm Tests =====" << std::endl ;
		formi.beSigned(buro);
		formi.execute(buro);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "===== Making objects =====" << std::endl ;
		Bureaucrat buro("pompom", 140);
		ShrubberyCreationForm formi("Shrub");

		std::cout << std::endl << "===== Bureaucrat Tests =====" << std::endl ;
		buro.signForm(formi);
		buro.executeForm(formi);
	}
	catch(const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	
	return(0);
}