#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Bureaucrat					employee("Employee", 150);
	Bureaucrat					manager("Manager", 50);
	Bureaucrat					boss("Boss", 1);
	ShrubberyCreationForm		shrubbery_creation("file");
	RobotomyRequestForm			robotomyRequestForm("Your neighbour");
	Intern						intern;
	AForm						*presidentialPardonForm;

	system("clear");
	presidentialPardonForm = intern.makeForm("presidential pardon", "target");

	std::cout << "FORM 1 SHRUBBERY CREATION FORM" << std::endl << std::endl;
	std::cout << shrubbery_creation;
	shrubbery_creation.execute(employee);
	employee.signForm(shrubbery_creation);
	manager.signForm(shrubbery_creation);
	shrubbery_creation.execute(employee);
	shrubbery_creation.execute(manager);
	std::cout << std::endl << std::endl;

	std::cout << "FORM 2 ROBOTOMY REQUEST FORM" << std::endl << std::endl;
	std::cout << robotomyRequestForm;
	robotomyRequestForm.execute(employee);
	employee.signForm(robotomyRequestForm);
	manager.signForm(robotomyRequestForm);
	robotomyRequestForm.execute(manager);
	robotomyRequestForm.execute(boss);
	std::cout << std::endl << std::endl;

	std::cout << "FORM 3 PRESIDENTIAL PARDON FORM" << std::endl << std::endl;
	std::cout << *presidentialPardonForm;
	presidentialPardonForm->execute(employee);
	manager.signForm(*presidentialPardonForm);
	boss.signForm(*presidentialPardonForm);
	presidentialPardonForm->execute(manager);
	presidentialPardonForm->execute(boss);

	delete presidentialPardonForm;
	return (0);
}