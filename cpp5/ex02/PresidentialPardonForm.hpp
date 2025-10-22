#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& to_copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& to_copy);
		~PresidentialPardonForm();

	void	executeAction() const;

	private:
		std::string _target;
	
};

#endif