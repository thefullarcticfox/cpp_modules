#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	name(name), grade(grade)
{
	if (this->grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name), grade(other.grade)
{
	*this = other;
}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.grade;
	return (*this);
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void				Bureaucrat::upGrade(void)
{
	if (this->grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->grade--;
}

void				Bureaucrat::downGrade(void)
{
	if (this->grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade++;
}

void				Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannot sign " << form <<
			" because " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(const Form& form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannot execute " << form <<
			" because " << e.what() << std::endl;
	}
}

std::ostream&		operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << "Bureaucrat " << bur.getName() << " (Grade " << bur.getGrade() << ")";
	return (os);
}

const char*			Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high to create or upgrade");
}

const char*			Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low to create or downgrade");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	const Bureaucrat::GradeTooHighException& other)
{
	*this = other;
}

Bureaucrat::GradeTooHighException&	Bureaucrat::GradeTooHighException::operator=(
	const Bureaucrat::GradeTooHighException& other)
{
	(void)other;
	return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	const Bureaucrat::GradeTooLowException& other)
{
	*this = other;
}

Bureaucrat::GradeTooLowException&	Bureaucrat::GradeTooLowException::operator=(
	const Bureaucrat::GradeTooLowException& other)
{
	(void)other;
	return (*this);
}
