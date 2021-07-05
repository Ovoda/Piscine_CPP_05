#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string param) : AForm("presidential pardon", 25, 5), _param(param)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("SrhubberyCreationForm", 145, 137)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	// not possible;
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i) {
	return (i.output(o));
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << _param << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	catch (AForm::FormIsNotSigned &e)
	{
		(void)e;
		std::cout << getName() << " is not signed" << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		(void)e;
		std::cout << executor.getName() << " 's grade is too low to execute " << getName() << std::endl;
	}
}

AForm	*PresidentialPardonForm::clone( std::string name, std::string target) const {
	AForm *copy = new PresidentialPardonForm(target);
	
	if (name == getName())
		return (copy);
	else
		delete copy;
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */