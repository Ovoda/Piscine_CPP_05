#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{

	public:
		// Constructors
		PresidentialPardonForm( std::string param );
		PresidentialPardonForm( PresidentialPardonForm const & src );

		// Destructor
		~PresidentialPardonForm();

		// Overload
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		// Methods
		void					execute( Bureaucrat const & executor ) const;
		AForm 	*clone( std::string name, std::string target ) const;


	private:
		PresidentialPardonForm( void );
		std::string	const	_param;

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ******************************************* PRESIDENTIALPARDONFORM_H */