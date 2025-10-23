#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

//CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default") {
	
	std::cout << "\033[90m✿ShrubberyCreationForm constructor called✿\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	
	std::cout << "\033[90m✿ShrubberyCreationForm constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy) : AForm(to_copy), _target(to_copy._target) {
	std::cout << "\033[90m✿ShrubberyCreationForm copy constructor called✿\033[0m" << std::endl;
}

//COPY ASSIGNMENT
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& to_copy) {
	std::cout << "\033[90m✿ShrubberyCreationForm copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_target = to_copy._target;
	}
	return (*this);
}

//DESTRUCTOR
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\033[90m~ShrubberyCreationForm destructor called\033[0m" << std::endl;
}

//PUBLIC
void ShrubberyCreationForm::executeAction() const
{
	// std::cout << "test\n";
	std::string file = _target + "_shrubbery";

	std::ofstream writeEnd(file.c_str());
	if (writeEnd.fail())
	{
		std::cout << "Couldn't create or write in " << file << std::endl;
		return;
	}

	writeEnd << "								# #### ####\n";
	writeEnd << "								### \\/#|### |/####\n";
	writeEnd << "							##\\/#/ \\||/##/_/##/_#\n";
	writeEnd << "							###  \\/###|/ \\/ # ###\n";
	writeEnd << "						##_\\_#\\_\\## | #/###_/_####\n";
	writeEnd << "						## #### # \\ #| /  #### ##/##\n";
	writeEnd << "						__#_--###`  |{,###---###-~\n";
	writeEnd << "									\\ }{\n";
	writeEnd << "									}}{\n";
	writeEnd << "									}}{\n";
	writeEnd << "								ejm  {{}\n";
	writeEnd << "								, -=-~{ .-^- _\n";
	writeEnd << "									`}\n";
	writeEnd << "									{\n\n\n\n";
	writeEnd << "		&&& &&  & &&\n";
	writeEnd << "	&& &\\/&\\|& ()|/ @, &&\n";
	writeEnd << "	&\\/(/&/&||/& /_/)_&/_&\n";
	writeEnd << "&() &\\/&|()|/&\\/ '%  & ()\n";
	writeEnd << "&_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	writeEnd << "&&   && & &| &| /& & % ()& /&&\n";
	writeEnd << "()&_---()&\\&±\\|&&-&&--%---()~\n";
	writeEnd << "	&&     \\|||\n";
	writeEnd << "			|||\n";
	writeEnd << "			|||\n";
	writeEnd << "			|||\n";
	writeEnd << "	, -=-~  .-^- _\n";
	writeEnd << "             `\n";


	writeEnd.close();
	std::cout << "Shrubbery has been planted in " << file << std::endl;
}
