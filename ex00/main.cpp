#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

int main(void)
{
    std::cout << "Test grade = 0" << std::endl;
    try
    {
        Bureaucrat zero("zero", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl
              << "Test grade = 1" << std::endl;
    try
    {
        Bureaucrat one("One", 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl
              << "Test grade = 2" << std::endl;
    try
    {
        Bureaucrat two("Two", 2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl
              << "Test grade = 155" << std::endl;
    try
    {
        Bureaucrat three("151", 155);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    {
        std::cout << std::endl
                  << "Test decrement" << std::endl;

        Bureaucrat grade_test("Jhin", 1);

        std::cout << grade_test;
        for (int i = 0; i < 6; i++)
        {
            std::cout << grade_test.getName() << " grade as been decremented" << std::endl;
            grade_test.decrementGrade();
            std::cout << grade_test;
        }
    }
    {
        std::cout << std::endl
                  << "Test increment" << std::endl;

        Bureaucrat grade_test("Jhin", 42);

        std::cout << grade_test;
        for (int i = 0; i < 6; i++)
        {
            std::cout << grade_test.getName() << " grade as been incremented" << std::endl;
            grade_test.incrementGrade();
            std::cout << grade_test;
        }
    }
    return (0);
}