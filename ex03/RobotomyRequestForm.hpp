#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
#include <stdlib.h>     // srand, rand
#include <time.h> 		// time
# include "AForm.hpp"

class RobotomyRequestForm : public AForm 
{

	public:
		// Constructors
		RobotomyRequestForm( std::string param );
		RobotomyRequestForm( RobotomyRequestForm const & src );

		// Destructor
		~RobotomyRequestForm();

		// Overload
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		// Methods
		void	execute( Bureaucrat const & executor ) const;
		AForm 	*clone( std::string name, std::string target ) const;

	private:
		RobotomyRequestForm( void );
		std::string	const	_param;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* ROBOTOMYREQUESTFORM_H */