#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Robotomy Request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	Form("Robotomy Request", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& other) : Form(other.getName(), 72, 45)
{
	*this = other;
}

RobotomyRequestForm&
		RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	this->setTarget(other.getTarget());
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::cout << "* VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRM *" << std::endl;
	if (std::rand() % 101 >= 50)
		std::cout << this->getTarget() << " has been robotomized successfully" <<
			std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
}
