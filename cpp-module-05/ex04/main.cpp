#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int		main(void)
{
	Intern      idiotOne;
	Bureaucrat  hermes = Bureaucrat("Hermes Conrad", 37);
	Bureaucrat  bob = Bureaucrat("Bobby Bobson", 70);
	OfficeBlock ob;

	std::srand(std::time(NULL));
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	try
	{
		ob.doBureaucracy("robotomy request", "Bender");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("robotomy request", "Bender");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		ob.doBureaucracy("shrubbery creation", "home");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		ob.doBureaucracy("presidential pardon", "Dude");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Upgrading " << bob << std::endl;
	while (bob.getGrade() > 15)
		bob.upGrade();
	std::cout << bob << std::endl;
	try
	{
		ob.doBureaucracy("presidential pardon", "Dude");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Upgrading " << hermes << std::endl;
	while (hermes.getGrade() > 5)
		hermes.upGrade();
	std::cout << hermes << std::endl;
	try
	{
		ob.doBureaucracy("presidential pardon", "Dude");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		ob.doBureaucracy("some unexisting form", "a");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
