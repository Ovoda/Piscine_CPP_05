#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string param) : AForm("robotomy request", 72, 45), _param(param)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("SrhubberyCreationForm", 145, 137)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	// not possible;
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i) {
	return (i.output(o));
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		srand (time(NULL));
		AForm::execute(executor);
		std::cout << executor.getName() << " executes " << getName() << std::endl;
		if (rand() % 2)
			std::cout << "Rizzzz... " << _param << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Rizzzz... " << _param << "'s operation is a failure !" << std::endl;

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

AForm	*RobotomyRequestForm::clone( std::string name, std::string target) const {
	AForm *copy = new RobotomyRequestForm(target);
	
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