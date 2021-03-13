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

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern		&Intern::operator=(Intern const &other)
{
	(void)other;
	return (*this);
}

Form		*Intern::makePresidentialPardon(std::string const &target)
{
	Form	*form = new PresidentialPardonForm(target);
	return (form);
}

Form		*Intern::makeRobotomyRequest(std::string const &target)
{
	Form	*form = new RobotomyRequestForm(target);
	return (form);
}

Form		*Intern::makeShrubberyCreation(std::string const &target)
{
	Form	*form = new ShrubberyCreationForm(target);
	return (form);
}

Form		*Intern::makeForm(std::string const &form,
	std::string const &target)
{
	std::string	formnames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	Form		*(Intern::*forms[3])(std::string const &) = {
		&Intern::makePresidentialPardon,
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation
	};
	int			i = -1;
	Form		*formptr = NULL;

	while (++i < 3)
		if (formnames[i].compare(form) == 0)
			formptr = (this->*forms[i])(target);
	if (formptr)
		std::cout << "Intern creates a " << *formptr << std::endl;
	else
		throw (Intern::FormNotFoundException());
	return (formptr);
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Form requested does not exist");
}

Intern::FormNotFoundException::FormNotFoundException() {}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

Intern::FormNotFoundException::FormNotFoundException(
	Intern::FormNotFoundException const &other)
{
	*this = other;
}

Intern::FormNotFoundException &Intern::FormNotFoundException::operator=(
	Intern::FormNotFoundException const &other)
{
	(void)other;
	return (*this);
}
