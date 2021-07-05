#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm 
{

	public:
		// Constructors
		ShrubberyCreationForm( std::string param );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );

		// Destructor
		~ShrubberyCreationForm();

		// Overload
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		// Methods
		void	execute( Bureaucrat const & executor ) const;

	private:
		ShrubberyCreationForm( void );
		std::string	const	_param;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */