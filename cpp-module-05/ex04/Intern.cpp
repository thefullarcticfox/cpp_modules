#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&		Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Form*		Intern::makePresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

Form*		Intern::makeRobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

Form*		Intern::makeShrubberyCreation(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

Form*		Intern::makeForm(const std::string& form,
	const std::string& target)
{
	std::string	formnames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	Form		*(Intern::*forms[3])(const std::string& ) = {
		&Intern::makePresidentialPardon,
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation
	};
	int			i = -1;
	Form*		formptr = NULL;

	while (++i < 3)
		if (formnames[i].compare(form) == 0)
			formptr = (this->*forms[i])(target);
	if (formptr)
		std::cout << "Intern creates a " << *formptr << std::endl;
	else
		throw (Intern::FormNotFoundException());
	return (formptr);
}

const char*	Intern::FormNotFoundException::what() const throw()
{
	return ("Form requested does not exist");
}

Intern::FormNotFoundException::FormNotFoundException() {}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

Intern::FormNotFoundException::FormNotFoundException(
	const Intern::FormNotFoundException& other)
{
	*this = other;
}

Intern::FormNotFoundException&	Intern::FormNotFoundException::operator=(
	const Intern::FormNotFoundException& other)
{
	(void)other;
	return (*this);
}
