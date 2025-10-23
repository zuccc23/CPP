#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl << "===== Try to create non existent form =====" << std::endl ;
	Bureaucrat buro("buroro", 20);
	Intern goodIntern;
	AForm* newForm;

	newForm = goodIntern.makeForm("non existent form", "targetti");
	if (newForm)
	{
		buro.executeForm(*newForm);
		delete newForm;
	}
	else
		std::cout << "No form created, cannot execute." << std::endl;

	std::cout << std::endl << "===== Subject Tests =====" << std::endl ;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	buro.signForm(*rrf);
	buro.executeForm(*rrf);
	
	return(0);
}