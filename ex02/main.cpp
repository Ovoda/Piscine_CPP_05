#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Bureaucrat					employee("Employee", 150);
	Bureaucrat					manager("Manager", 50);
	Bureaucrat					boss("Boss", 1);
	ShrubberyCreationForm		shrubbery_creation("../ex00");
	RobotomyRequestForm			robotomyRequestForm("Your neighbour");
	PresidentialPardonForm		PresidentialPardonForm("Your dog");

	system("clear");
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
	std::cout << PresidentialPardonForm;
	PresidentialPardonForm.execute(employee);
	manager.signForm(PresidentialPardonForm);
	boss.signForm(PresidentialPardonForm);
	robotomyRequestForm.execute(manager);
	PresidentialPardonForm.execute(boss);
	return (0);
}
