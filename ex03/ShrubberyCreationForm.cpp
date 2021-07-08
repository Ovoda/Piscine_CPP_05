#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string param) : AForm("shrubbery creation", 145, 137), _param(param)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("shrubbery creation", 145, 137)
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	// not possible;
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i) {
	return (i.output(o));
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::execute(executor);
		std::cout << executor.getName() << " executes " << getName() << std::endl;

		std::ofstream ofile(_param.c_str());
		if (ofile.fail())
		{
			std::cout << "Cannot open file" << std::endl;
		}
		ofile << "	 .        +          .      .          ." << std::endl;
		ofile << "     .            _        .                    ." << std::endl;
		ofile << "  ,              /;-._,-.____        ,-----.__" << std::endl;
		ofile << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
		ofile << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
		ofile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
		ofile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
		ofile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
		ofile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
		ofile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
		ofile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
		ofile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
		ofile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
		ofile << "                    \\::.  :\\/:'  /              +" << std::endl;
		ofile << "   .                 `.:.  /:'  }      ." << std::endl;
		ofile << "           .           ):_(:;   \\           ." << std::endl;
		ofile << "                      /:. _/ ,  |" << std::endl;
		ofile << "                   . (|::.     ,`                  ." << std::endl;
		ofile << "     .                |::.    {\\" << std::endl;
		ofile << "                      |::.\\  \\ `." << std::endl;
		ofile << "                      |:::(\\    |" << std::endl;
		ofile << "              O       |:::/{ }  |                  (o" << std::endl;
		ofile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
		ofile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		ofile << "   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~" << std::endl;
		ofile.close();
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


AForm	*ShrubberyCreationForm::clone( std::string name, std::string target) const {
	AForm *copy = new ShrubberyCreationForm(target);
	
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