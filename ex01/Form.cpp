#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form( void ) : _min_signing_grade(0), _min_execution_grade(0), _is_signed(false) {
	// Shouldn't be used;
}

Form::Form( std::string name, unsigned int min_signing_grade, unsigned int min_execution_grade )
:	_name(name), _min_signing_grade(min_signing_grade),
	_min_execution_grade(min_execution_grade), _is_signed(false)
{
	
	if (_min_signing_grade < 1 || _min_execution_grade < 1)
		throw grade_too_high_exception;
	if (_min_signing_grade > 150 || _min_execution_grade > 150)
		throw grade_too_low_exception;

}

Form::Form(const Form &src) : _name(src.getName()), _min_signing_grade(src.getMinSigningGrade()),
							_min_execution_grade(src.getMinExecutionGrade()), _is_signed(src.getIsSigned())
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		_is_signed = rhs.getIsSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << "Form " << i.getName()
	<< ", Min Signing Grade required [" << i.getMinSigningGrade()
	<< "] , Min Execution Grade required [" << i.getMinExecutionGrade();
	if (i.getIsSigned() == true)
		o << "], has been signed" << std::endl;
	else
		o << "], has not been signed" << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= _min_signing_grade)
		_is_signed = true;
	else
		throw grade_too_low_exception;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Form::getName(void) const
{
	return (_name);
}

unsigned int Form::getMinSigningGrade(void) const
{
	return (_min_signing_grade);
}

unsigned int Form::getMinExecutionGrade(void) const
{
	return (_min_execution_grade);
}

bool Form::getIsSigned(void) const
{
	return (_is_signed);
}

/* ************************************************************************** */