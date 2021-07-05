#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:
		// Constructors
		Form( std::string name, unsigned int min_signing_grade, unsigned int min_execution_grade );
		Form( Form const & src );

		// Destructor
		~Form();

		// Overload
		Form &				operator=( Form const & rhs );

		// Getters
		std::string const	getName( void ) const;
		unsigned int 		getMinSigningGrade( void ) const;
		unsigned int 		getMinExecutionGrade( void ) const;
		bool				getIsSigned( void ) const;

		// Methods
		void				beSigned( Bureaucrat &bureaucrat );

		// Exceptions
		class GradeTooLowException : public std::exception {
			public:
				const char * what( void ) const throw() {
					return ("[Exception] grade is to low");
				}
 		} grade_too_low_exception;

		class GradeTooHighException : public std::exception {
			public:
				const char *what( void ) const throw() {
					return ("[Exception] grade is to high");
				}
 		} grade_too_high_exception;

	private:
		Form( void );
		std::string const	_name;
		unsigned int const	_min_signing_grade;
		unsigned int const	_min_execution_grade;
		bool				_is_signed;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */