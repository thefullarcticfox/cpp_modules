#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("President Pardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	Form("President Pardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& other) : Form(other.getName(), 25, 5)
{
	*this = other;
}

PresidentialPardonForm&
		PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->setTarget(other.getTarget());
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." <<
		std::endl;
}
