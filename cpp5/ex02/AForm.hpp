#ifndef AFORM_HPP

# define AFORM_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(std::string new_name, int new_gradeToSign, int new_gradeToExecute);
		AForm(const AForm& to_copy);
		AForm& operator=(const AForm& to_copy);
		virtual ~AForm();

		std::string	getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool getSign() const;
		void	beSigned(Bureaucrat& buro);
		void	execute(Bureaucrat const & executor) const;
		
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class UnsignedException : public std::exception {
			const char* what() const throw();
		};

	protected:
		virtual void	executeAction() const = 0;

	private:
		const std::string _name;
		bool	_isSigned;
		const	int _gradeToSign;
		const	int _gradeToExecute;

	
};

std::ostream &operator<<(std::ostream &output_stream, const AForm &form);

#endif