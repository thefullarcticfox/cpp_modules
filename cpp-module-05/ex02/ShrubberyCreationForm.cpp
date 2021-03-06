#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("Shrubbery Creation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	Form("Shrubbery Creation", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& other) : Form(other.getName(), 145, 137)
{
	*this = other;
}

ShrubberyCreationForm&
		ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	this->setTarget(other.getTarget());
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	Form::execute(executor);
	std::ofstream	dst((this->getTarget() + "_shrubbery").c_str());
	if (!dst.is_open())
		throw (ShrubberyCreationForm::FileWriteFailureException());
	dst <<
		"             ,@@@@@@@," << std::endl <<
		"     ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl <<
		"  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl <<
		" ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl <<
		" %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl <<
		" %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl <<
		" `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl <<
		"     |o|        | |         | |" << std::endl <<
		"     |.|        | |         | |" << std::endl <<
		"  \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	dst.close();
}

const char*	ShrubberyCreationForm::FileWriteFailureException::what()
	const throw()
{
	return ("Cannot write a shrubbery file");
}

ShrubberyCreationForm::FileWriteFailureException::FileWriteFailureException() {}

ShrubberyCreationForm::FileWriteFailureException::~FileWriteFailureException() throw() {}

ShrubberyCreationForm::FileWriteFailureException::FileWriteFailureException(
	const ShrubberyCreationForm::FileWriteFailureException& other)
{
	*this = other;
}

ShrubberyCreationForm::FileWriteFailureException&
	ShrubberyCreationForm::FileWriteFailureException::operator=(
	const ShrubberyCreationForm::FileWriteFailureException& other)
{
	(void)other;
	return (*this);
}
