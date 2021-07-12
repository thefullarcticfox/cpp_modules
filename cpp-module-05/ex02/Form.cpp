#include "Form.hpp"

Form::Form() : signgrade(1), execgrade(1)
{
	this->_issigned = false;
}

Form::Form(const std::string& name, int signgrade, const int execgrade) :
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

Form::Form(const Form& other) : name(other.name),
	signgrade(other.signgrade), execgrade(other.execgrade)
{
	if (this->signgrade < 1 || this->execgrade < 1)
		throw (Form::GradeTooHighException());
	if (this->signgrade > 150 || this->execgrade > 150)
		throw (Form::GradeTooLowException());
	*this = other;
}

Form&				Form::operator=(const Form& other)
{
	this->_issigned = other._issigned;
	return (*this);
}

const std::string&	Form::getName(void) const
{
	return (this->name);
}

const std::string&	Form::getTarget(void) const
{
	return (this->target);
}

void				Form::setTarget(const std::string& target)
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

void				Form::beSigned(const Bureaucrat& bur)
{
	if (this->_issigned)
		throw (Form::AlreadySignedException());
	if (bur.getGrade() > this->signgrade)
		throw (Form::GradeTooLowToSignException());
	std::cout << bur << " signs a " << *this << std::endl;
	this->_issigned = true;
}

void				Form::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw (Form::NotSignedException());
	if (executor.getGrade() > this->getExecGrade())
		throw (Form::GradeTooLowToExecuteException());
	std::cout << executor << " executes a " << *this << std::endl;
}

std::ostream&		operator<<(std::ostream& os, const Form& form)
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

const char*			Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high to create");
}

const char*			Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low to create");
}

const char*			Form::AlreadySignedException::what() const throw()
{
	return ("Form is signed");
}

const char*			Form::GradeTooLowToSignException::what() const throw()
{
	return ("Bureaucrat grade is too low to sign this form");
}

const char*			Form::GradeTooLowToExecuteException::what() const throw()
{
	return ("Bureaucrat grade is too low to execute this form");
}

const char*			Form::NotSignedException::what() const throw()
{
	return ("Unsigned form can't be executed");
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooHighException::GradeTooHighException(
	const Form::GradeTooHighException& other)
{
	*this = other;
}

Form::GradeTooHighException&	Form::GradeTooHighException::operator=(
	const Form::GradeTooHighException& other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

Form::GradeTooLowException::GradeTooLowException(
	const Form::GradeTooLowException& other)
{
	*this = other;
}

Form::GradeTooLowException&	Form::GradeTooLowException::operator=(
	const Form::GradeTooLowException& other)
{
	(void)other;
	return (*this);
}

Form::AlreadySignedException::AlreadySignedException() {}

Form::AlreadySignedException::~AlreadySignedException() throw() {}

Form::AlreadySignedException::AlreadySignedException(
	const Form::AlreadySignedException& other)
{
	*this = other;
}

Form::AlreadySignedException&	Form::AlreadySignedException::operator=(
	const Form::AlreadySignedException& other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowToSignException::GradeTooLowToSignException() {}

Form::GradeTooLowToSignException::~GradeTooLowToSignException() throw() {}

Form::GradeTooLowToSignException::GradeTooLowToSignException(
	const Form::GradeTooLowToSignException& other)
{
	*this = other;
}

Form::GradeTooLowToSignException&	Form::GradeTooLowToSignException::operator=(
	const Form::GradeTooLowToSignException& other)
{
	(void)other;
	return (*this);
}

Form::GradeTooLowToExecuteException::GradeTooLowToExecuteException() {}

Form::GradeTooLowToExecuteException::~GradeTooLowToExecuteException() throw() {}

Form::GradeTooLowToExecuteException::GradeTooLowToExecuteException(
	const Form::GradeTooLowToExecuteException& other)
{
	*this = other;
}

Form::GradeTooLowToExecuteException&	Form::GradeTooLowToExecuteException::operator=(
	const Form::GradeTooLowToExecuteException& other)
{
	(void)other;
	return (*this);
}

Form::NotSignedException::NotSignedException() {}

Form::NotSignedException::~NotSignedException() throw() {}

Form::NotSignedException::NotSignedException(
	const Form::NotSignedException& other)
{
	*this = other;
}

Form::NotSignedException&	Form::NotSignedException::operator=(
	const Form::NotSignedException& other)
{
	(void)other;
	return (*this);
}
