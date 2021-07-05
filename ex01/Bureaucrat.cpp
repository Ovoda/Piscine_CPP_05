#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(void)
{
	// Shouldn't be used;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{

	if (_grade < 1)
		throw grade_too_high_exception;
	else if (grade > 150)
		throw grade_too_low_exception;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		_grade = rhs.getGrade();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(void)
{
	if (_grade > 1)
		_grade -= 1;
	else
		std::cout << "Grade cannot be higher than 1" << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade < 150)
		_grade += 1;
	else
		std::cout << "Grade cannot be lower than 150" << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << " cannot sign " << form.getName()
				  << " because his grade is too low" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Bureaucrat::getName(void) const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

/* ************************************************************************** */