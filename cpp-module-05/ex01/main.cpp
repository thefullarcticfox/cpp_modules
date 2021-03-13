#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void)
{
	try
	{
		Form		form("F29A", 0, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		form("F29A", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	josh("Josh", 18);
		std::cout << josh << std::endl;
		Form		form("F29A", 17, 4);
		std::cout << form << std::endl;
		josh.signForm(form);
		josh.upGrade();
		std::cout << josh << std::endl;
		josh.signForm(form);
		std::cout << form << std::endl;
		josh.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
