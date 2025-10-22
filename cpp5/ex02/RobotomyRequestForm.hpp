#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& to_copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& to_copy);
		~RobotomyRequestForm();

	void	executeAction() const;

	private:
		std::string _target;
	
};


#endif