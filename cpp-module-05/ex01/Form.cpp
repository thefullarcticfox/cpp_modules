#include "Form.hpp"

Form::Form() : signgrade(1), execgrade(1)
{
	this->_issigned = false;
}

Form::Form(const std::string& name, int signgrade, int const execgrade) :
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
		throw (Form::GradeTooLowException());
	std::cout << bur << " signs a " << *this << std::endl;
	this->_issigned = true;
}

std::ostream&		operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " Form (s.grade " << form.getSignGrade() <<
		", ex.grade "<< form.getExecGrade() << ")";
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
	return ("Form grade is too low to create or Bureaucrat grade too low to sign");
}

const char*			Form::AlreadySignedException::what() const throw()
{
	return ("Form is signed");
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
