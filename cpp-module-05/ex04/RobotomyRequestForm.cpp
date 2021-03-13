#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("Robotomy Request", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
	Form("Robotomy Request", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(
	RobotomyRequestForm const &other) : Form(other.getName(), 72, 45)
{
	*this = other;
}

RobotomyRequestForm
		&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->setTarget(other.getTarget());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "* VRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRM *" << std::endl;
	if (std::rand() % 101 >= 50)
		std::cout << this->getTarget() << " has been robotomized successfully" <<
			std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
}
