#ifndef INTERN_HPP

# define INTERN_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& to_copy);
		Intern& operator=(const Intern& to_copy);
		~Intern();

		AForm* makeForm(std::string formName, std::string formTarget);

	private:
	
};

AForm* createShrubbery(const std::string& target);
AForm* createRobotomy(const std::string& target);
AForm* createPresidential(const std::string& target);

#endif