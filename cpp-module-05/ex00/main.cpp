#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

int		main(void)
{
	try
	{
		Bureaucrat	josh("Josh", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	josh("Josh", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	josh("Josh", 145);
		std::cout << josh << std::endl;
		std::cout << "downgrading " << josh.getName() << std::endl;
		while (1)
		{
			josh.downGrade();
			std::cout << josh << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Bureaucrat	josh2("Josh2", 5);
		std::cout << josh2 << std::endl;
		std::cout << "upgrading " << josh2.getName() << std::endl;
		while (1)
		{
			josh2.upGrade();
			std::cout << josh2 << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
