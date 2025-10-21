#ifndef FORM_HPP

# define FORM_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Form {
	public:
		Form();
		Form(std::string new_name, int new_gradeToSign, int new_gradeToExecute);
		Form(const Form& to_copy);
		Form& operator=(const Form& to_copy);
		~Form();

		std::string	getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool getSign() const;

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

	private:
		const std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;

	
};

std::ostream &operator<<(std::ostream &output_stream, const Form &form);

#endif