#include "Form.hpp"

Form::Form() : signgrade(1), execgrade(1)
{
	this->_issigned = false;
}

Form::Form(std::string const &name, int const &signgrade, int const execgrade) :
	name(name), signgrade(signgrade), execgrade(execgrade)
{
	if (this->signgrade < 1 || this->execgrade < 1)
		throw (Form::GradeTooHighException());
	if (this->signgrade > 150 || this->execgrade > 150)
		throw (Form::GradeTooLowException());
	this->_issigned = false;
}

Form::~Form()
{
}

Form::Form(Form const &other) : name(other.name),
	signgrade(other.signgrade), execgrade(other.execgrade)
{
	if (this->signgrade < 1 || this->execgrade < 1)
		throw (Form::GradeTooHighException());
	if (this->signgrade > 150 || this->execgrade > 150)
		throw (Form::GradeTooLowException());
	*this = other;
}

Form				&Form::operator=(Form const &other)
{
	this->_issigned = other._issigned;
	return (*this);
}

std::string const	&Form::getName(void) const
{
	return (this->name);
}

std::string const	&Form::getTarget(void) const
{
	return (this->target);
}

void				Form::setTarget(std::string const &target)
{
	this->target = target;
}

int					Form::getSignGrade(void) const
{
	return (this->signgrade);
}

int					Form::getExecGrade(void) const
{
	return (this->execgrade);
}

bool				Form::isSigned(void) const
{
	return (this->_issigned);
}

void				Form::beSigned(Bureaucrat const &bur)
{
	if (this->_issigned)
		throw (Form::AlreadySignedException());
	if (bur.getGrade() > this->signgrade)
		throw (Form::GradeTooLowToSignException());
	std::cout << bur << " signs a " << *this << std::endl;
	this->_issigned = true;
}

void				Form::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (Form::GradeTooLowToExecuteException());
	std::cout << executor << " executes a " << *this << std::endl;
}

std::ostream		&operator<<(std::ostream &os, Form const &form)
{
	os << form.getName() << " Form (s.grade " << form.getSignGrade() <<
		", ex.grade "<< form.getExecGrade() << ") targeted on " <<
		form.getTarget();
	if (form.isSigned())
		os << " (Signed)";
	else
		os << " (Unsigned)";
	return (os);
}

const char			*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high to create");
}

const char			*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low to create");
}

const char			*Form::AlreadySignedException::what() const throw()
{
	return ("Form is signed");
}

const char			*Form::GradeTooLowToSignException::what() const throw()
{
	return ("Bureaucrat grade is too low to sign this form");
}

const char			*Form::GradeTooLowToExecuteException::what() const throw()
{
	return ("Bureaucrat grade is too low to execute this form");
}

const char			*Form::NotSignedException::what() const throw()
{
	return ("Unsigned form can't be executed");
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(
	Form::GradeTooHighException const &other)
{
	*this = other;
}

Form::GradeTooHighException &Form::GradeTooHighException::operator=(
	Form::GradeTooHighException const &other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(
	Form::GradeTooLowException const &other)
{
	*this = other;
}

Form::GradeTooLowException &Form::GradeTooLowException::operator=(
	Form::GradeTooLowException const &other)
{
	(void)other;
	return (*this);
}

Form::AlreadySignedException::AlreadySignedException() {}

Form::AlreadySignedException::~AlreadySignedException() throw() {}

Form::AlreadySignedException::AlreadySignedException(
	Form::AlreadySignedException const &other)
{
	*this = other;
}

Form::AlreadySignedException &Form::AlreadySignedException::operator=(
	Form::AlreadySignedException const &other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowToSignException::GradeTooLowToSignException() {}

Form::GradeTooLowToSignException::~GradeTooLowToSignException() throw() {}

Form::GradeTooLowToSignException::GradeTooLowToSignException(
	Form::GradeTooLowToSignException const &other)
{
	*this = other;
}

Form::GradeTooLowToSignException &Form::GradeTooLowToSignException::operator=(
	Form::GradeTooLowToSignException const &other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowToExecuteException::GradeTooLowToExecuteException() {}

Form::GradeTooLowToExecuteException::~GradeTooLowToExecuteException() throw() {}

Form::GradeTooLowToExecuteException::GradeTooLowToExecuteException(
	Form::GradeTooLowToExecuteException const &other)
{
	*this = other;
}

Form::GradeTooLowToExecuteException &Form::GradeTooLowToExecuteException::operator=(
	Form::GradeTooLowToExecuteException const &other)
{
	(void)other;
	return (*this);
}

Form::NotSignedException::NotSignedException() {}

Form::NotSignedException::~NotSignedException() throw() {}

Form::NotSignedException::NotSignedException(
	Form::NotSignedException const &other)
{
	*this = other;
}

Form::NotSignedException &Form::NotSignedException::operator=(
	Form::NotSignedException const &other)
{
	(void)other;
	return (*this);
}
