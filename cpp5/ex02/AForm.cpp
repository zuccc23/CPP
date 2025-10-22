#include "AForm.hpp"
#include "Bureaucrat.hpp"

//CONSTRUCTOR
AForm::AForm() : _name("default"), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "\033[90mForm constructor called.\033[0m" << std::endl;
}

AForm::AForm(std::string new_name, int new_gradeToSign, int new_gradeToExecute) : _name(new_name), _gradeToSign(new_gradeToSign), _gradeToExecute(new_gradeToExecute){
	_isSigned = false;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "\033[90mForm constructor called.\033[0m" << std::endl;
}

//COPY CONSTRUCTOR
AForm::AForm(const AForm& to_copy) : _name(to_copy._name), _gradeToSign(to_copy._gradeToSign), _gradeToExecute(to_copy._gradeToExecute) {
	std::cout << "\033[90mForm copy constructor called.\033[0m" << std::endl;
	*this = to_copy;
}

//COPY ASSIGNMENT
AForm& AForm::operator=(const AForm& to_copy) {
	std::cout << "\033[90mForm copy assignment operator called.\033[0m" << std::endl;
	if (this != &to_copy)
	{
		_isSigned = to_copy._isSigned;
	}
	return (*this);
}

//DESTRUCTOR
AForm::~AForm() {
	std::cout << "\033[90mForm destructor called.\033[0m" << std::endl;
}

//PUBLIC
std::string	AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

bool	AForm::getSign() const
{
	return (_isSigned);
}

void	AForm::beSigned(Bureaucrat& buro)
{
	if (_gradeToSign < buro.getGrade())
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw UnsignedException();
	else if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	executeAction();
}

void	AForm::executeAction() const
{
}

//Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Required grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Required grade is too low.");
}

const char* AForm::UnsignedException::what() const throw()
{
	return ("The form is not signed, and cannot be executed.");
}

//NON MEMBER
std::ostream &operator<<(std::ostream &output_stream, const AForm &form)
{
	if (form.getSign() == true)
		output_stream << form.getName() << " form is signed. It requires a grade of " << form.getGradeToSign() << " to be signed, and a grade of " << form.getGradeToExecute() << " to be executed." << std::endl;
	else if (form.getSign() == false)
		output_stream << form.getName() << " form is not signed. It requires a grade of " << form.getGradeToSign() << " to be signed, and a grade of " << form.getGradeToExecute() << " to be executed." << std::endl;
	return (output_stream);
}
