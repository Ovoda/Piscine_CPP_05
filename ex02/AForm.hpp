#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

public:
	// Constructors
	AForm(std::string name, unsigned int min_signing_grade, unsigned int min_execution_grade);
	AForm(AForm const &src);

	// Destructor
	~AForm();

	// Overload
	AForm &operator=(AForm const &rhs);

	// Getters
	std::string const getName(void) const;
	unsigned int getMinSigningGrade(void) const;
	unsigned int getMinExecutionGrade(void) const;
	bool getIsSigned(void) const;

	// Methods
	void 			beSigned(Bureaucrat &bureaucrat);
	virtual void 	execute(Bureaucrat const &executor) const = 0;
	std::ostream	&output( std::ostream & o ) const;

	// Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("[Exception] grade is to low");
		}
	} grade_too_low_exception;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("[Exception] grade is to high");
		}
	} grade_too_high_exception;

	class FormIsNotSigned : public std::exception
	{
	public:
		const char *what(void) const throw()
		{
			return ("[Exception] aform is not signed");
		}
	} form_is_not_signed;

private:
	AForm(void);
	std::string const 	_name;
	unsigned int const 	_min_signing_grade;
	unsigned int const 	_min_execution_grade;
	bool 				_is_signed;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif /* ************************************************************ AFORM_H */