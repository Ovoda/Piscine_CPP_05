#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm( void ) : _min_signing_grade(0), _min_execution_grade(0) {
	// Shouldn't be used;
}

AForm::AForm( std::string name, unsigned int min_signing_grade, unsigned int min_execution_grade )
:	_name(name), _min_signing_grade(min_signing_grade),
	_min_execution_grade(min_execution_grade), _is_signed(false)
{
	
	if (_min_signing_grade < 1 || _min_execution_grade < 1)
		throw grade_too_high_exception;
	if (_min_signing_grade > 150 || _min_execution_grade > 150)
		throw grade_too_low_exception;

}

AForm::AForm(const AForm &src) : _name(src.getName()), _min_signing_grade(src.getMinSigningGrade()),
							_min_execution_grade(src.getMinExecutionGrade()), _is_signed(src.getIsSigned())
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		_is_signed = rhs.getIsSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "Form : " << i.getName()
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

void		AForm::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() <= _min_signing_grade)
		_is_signed = true;
	else
		throw grade_too_low_exception;
}

void		AForm::execute( Bureaucrat const & executor ) const {
	if (_is_signed == false)
		throw form_is_not_signed;
	else if (_is_signed == true && executor.getGrade() > _min_execution_grade)
		throw grade_too_low_exception;
	else
		std::cout << executor.getName() << " executes " << getName() << std::endl;
}

std::ostream	&AForm::output( std::ostream & o ) const {
	o << *this;
	return (o);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const AForm::getName(void) const
{
	return (_name);
}

unsigned int AForm::getMinSigningGrade(void) const
{
	return (_min_signing_grade);
}

unsigned int AForm::getMinExecutionGrade(void) const
{
	return (_min_execution_grade);
}

bool AForm::getIsSigned(void) const
{
	return (_is_signed);
}

/* ************************************************************************** */