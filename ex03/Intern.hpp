#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

	public:
		// Constructors
		Intern( void );
		Intern( Intern const & src );
		
		// Destructor
		~Intern();

		// Overload
		Intern &		operator=( Intern const & rhs );

		// Methods
		AForm	*makeForm(std::string form_name, std::string target);

	private:

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */