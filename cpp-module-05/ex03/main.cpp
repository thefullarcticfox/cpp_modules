#include <iostream>
#include <string>
#include <exception>
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int		main(void)
{
	Intern		someRandomIntern;
	Form*	form1 = NULL;
	Form*	form2 = NULL;
	Form*	form3 = NULL;
	Form*	noform = NULL;

	std::srand(std::time(NULL));
	try
	{
		Bureaucrat	josh("Josh", 145);
		std::cout << josh << std::endl;
		std::cout << "----------------------------------------" << std::endl;

		form1 = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *form1 << std::endl;
		josh.executeForm(*form1);
		josh.signForm(*form1);
		std::cout << *form1 << std::endl;
		josh.executeForm(*form1);
		std::cout << "Upgrading " << josh << std::endl;
		for (int i = 0; i < 10; i++)
			josh.upGrade();
		std::cout << josh << std::endl;
		josh.executeForm(*form1);

		std::cout << "----------------------------------------" << std::endl;

		form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form2 << std::endl;
		josh.executeForm(*form2);
		josh.signForm(*form2);
		std::cout << "Upgrading " << josh << std::endl;
		for (int i = 0; i < 70; i++)
			josh.upGrade();
		std::cout << josh << std::endl;
		josh.signForm(*form2);
		std::cout << *form2 << std::endl;
		josh.executeForm(*form2);
		std::cout << "Upgrading " << josh << std::endl;
		for (int i = 0; i < 20; i++)
			josh.upGrade();
		std::cout << josh << std::endl;
		josh.executeForm(*form2);

		std::cout << "----------------------------------------" << std::endl;

		form3 = someRandomIntern.makeForm("presidential pardon", "Dude");
		std::cout << *form3 << std::endl;
		josh.executeForm(*form3);
		josh.signForm(*form3);
		std::cout << "Upgrading " << josh << std::endl;
		for (int i = 0; i < 20; i++)
			josh.upGrade();
		std::cout << josh << std::endl;
		josh.signForm(*form3);
		std::cout << *form3 << std::endl;
		josh.executeForm(*form3);
		std::cout << "Upgrading " << josh << std::endl;
		for (int i = 0; i < 20; i++)
			josh.upGrade();
		std::cout << josh << std::endl;
		josh.executeForm(*form3);

		std::cout << "----------------------------------------" << std::endl;

		noform = someRandomIntern.makeForm("random form thingy", "test");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete (form1);
	delete (form2);
	delete (form3);
	delete (noform);
	return (0);
}
