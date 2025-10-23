#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& to_copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& to_copy);
		~ShrubberyCreationForm();

		void	executeAction() const;

	private:
		std::string _target;
	
};

#endif
