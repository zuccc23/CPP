#include "Form.hpp"
#include "Bureaucrat.hpp"

//CONSTRUCTOR
Form::Form() : _name("default"), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "\033[90m✿Form constructor called✿\033[0m" << std::endl;
}

Form::Form(std::string new_name, int new_gradeToSign, int new_gradeToExecute) : _name(new_name), _gradeToSign(new_gradeToSign), _gradeToExecute(new_gradeToExecute){
	_isSigned = false;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "\033[90m✿Form constructor called✿\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
Form::Form(const Form& to_copy) : _name(to_copy._name), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute) {
	std::cout << "\033[90m✿Form copy constructor called✿\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
Form& Form::operator=(const Form& to_copy) {
	std::cout << "\033[90m✿Form copy assignment operator called✿\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_isSigned = to_copy._isSigned;
	}
	return (*this);
}

//DESTRUCTOR
Form::~Form() {
	std::cout << "\033[90m~Form destructor called\033[0m" << std::endl;
}

//PUBLIC
std::string	Form::getName() const
{
	return (_name);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	Form::getSign() const
{
	return (_isSigned);
}

void	Form::beSigned(Bureaucrat& buro)
{
	if (_gradeToSign < buro.getGrade())
		throw GradeTooLowException();
	else
		_isSigned = true;
}

//Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Required grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Required grade is too low.");
}

//NON MEMBER
std::ostream &operator<<(std::ostream &output_stream, const Form &form)
{
	if (form.getSign() == true)
		output_stream << form.getName() << " form is signed. It requires a grade of " << form.getGradeToSign() << " to be signed, and a grade of " << form.getGradeToExecute() << " to be executed." << std::endl;
	else if (form.getSign() == false)
		output_stream << form.getName() << " form is not signed. It requires a grade of " << form.getGradeToSign() << " to be signed, and a grade of " << form.getGradeToExecute() << " to be executed." << std::endl;
	return (output_stream);
}
