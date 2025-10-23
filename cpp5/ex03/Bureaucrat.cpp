#include "Bureaucrat.hpp"
#include "AForm.hpp"

//CONSTRUCTOR
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "\033[90m✿Bureaucrat constructor called✿\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : _name(new_name), _grade(new_grade) {
	std::cout << "\033[90m✿Bureaucrat constructor called✿\033[0m" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

//COPY CONSTRUCTOR
Bureaucrat::Bureaucrat(const Bureaucrat& to_copy) : _name(to_copy._name) {
	std::cout << "\033[90m✿Bureaucrat copy constructor called✿\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& to_copy) {
	std::cout << "\033[90m✿Bureaucrat copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_grade = to_copy._grade;
	}
	return (*this);
}

//DESTRUCTOR
Bureaucrat::~Bureaucrat() {
	std::cout << "\033[90m~Bureaucrat destructor called.\033[0m" << std::endl;
}

//PUBLIC
std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because the bureaucrat's grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Could not execute the form: " << e.what() << std::endl;
	}
}

Bureaucrat&	Bureaucrat::operator++(void)
{
	_grade -= 1;
	if (_grade < 1)
		throw GradeTooHighException();
	return (*this);
}

Bureaucrat&	Bureaucrat::operator--(void)
{
	_grade += 1;
	if (_grade > 150)
		throw GradeTooLowException();
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat temp(*this);
	_grade -= 1;
	if (_grade < 1)
		throw GradeTooHighException();
	return temp;
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat temp(*this);
	_grade += 1;
	if (_grade > 150)
		throw GradeTooLowException();
	return temp;
}

//Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

//NON MEMBER
std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &buro)
{
	output_stream << buro.getName() << ", bureaucrat grade " << buro.getGrade() << std::endl;
	return (output_stream);
}