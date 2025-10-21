#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string new_name, int new_grade);
		Bureaucrat(const Bureaucrat& to_copy);
		Bureaucrat& operator=(const Bureaucrat& to_copy);
		~Bureaucrat();

		std::string	getName() const;
		int	getGrade() const;

		Bureaucrat&	operator++(void);
		Bureaucrat&	operator--(void);
		Bureaucrat	operator++(int);
		Bureaucrat	operator--(int);

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

	private:
		const	std::string _name;
		int		_grade;
	
};

std::ostream &operator<<(std::ostream &output_stream, const Bureaucrat &buro);

#endif