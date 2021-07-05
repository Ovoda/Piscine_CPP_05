#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Bureaucrat	employee("Employee", 150);
	Bureaucrat	manager("Manager", 100);
	Bureaucrat	boss("Boss", 1);
	Form		contract("Contract-40721", 150, 150);
	Form		salary("Salary-40721", 100, 100);
	Form		partnership("Partnership-40721", 1, 1);

	std::cout << contract << salary << partnership << std::endl;

	employee.signForm(contract);
	employee.signForm(salary);
	employee.signForm(partnership);
	std::cout << std::endl;
	manager.signForm(contract);
	manager.signForm(salary);
	manager.signForm(partnership);
	std::cout << std::endl;
	boss.signForm(contract);
	boss.signForm(salary);
	boss.signForm(partnership);
	std::cout << std::endl;
	std::cout << contract << salary << partnership << std::endl;
	return (0);
}