#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{

public:
	// Constructors
	Bureaucrat( std::string name, unsigned int grade );
	Bureaucrat( Bureaucrat const &src );

	// Destructor
	~Bureaucrat();

	// Overload
	Bureaucrat &operator=(Bureaucrat const &rhs);

	// Getters
	std::string const getName(void) const;
	unsigned int getGrade(void) const;

	// Methods
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm( Form & form );

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw() {
			return ("[Exception] : grade is too high");
		}
	} grade_too_high_exception;

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw() {
			return ("[Exception] : grade is too low");
		}
	} grade_too_low_exception;
private:
	Bureaucrat(void);
	std::string const	_name;
	unsigned int 		_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H */