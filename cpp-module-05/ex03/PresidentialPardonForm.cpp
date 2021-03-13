#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("President Pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	Form("President Pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const &other) : Form(other.getName(), 25, 5)
{
	*this = other;
}

PresidentialPardonForm
		&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	this->setTarget(other.getTarget());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." <<
		std::endl;
}
