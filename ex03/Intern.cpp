#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern( void ) {
}

Intern::Intern( const Intern & src ) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	// not possible;
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "I'm just an intern" << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm	*Intern::makeForm( std::string form_name, std::string target)
{
	AForm *tmp;
	ShrubberyCreationForm 		*shr = new ShrubberyCreationForm(target);
	RobotomyRequestForm			*rob = new RobotomyRequestForm(target);
	PresidentialPardonForm		*pre = new PresidentialPardonForm(target);
	AForm *forms[3] = {shr, rob, pre};
	int	i = 0;
	tmp = 0;

	while (i < 3)
	{
		if (form_name == forms[i]->getName())
		{
			tmp = forms[i];
			std::cout << "Intern creates " << forms[i]->getName() << std::endl;
			break ;
		}
		i++; 
	}
	i = 0;
	while (i < 3)
	{
		if (tmp != forms[i])
			delete forms[i];
		i++;
	}
	return (tmp);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */