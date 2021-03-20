#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
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

Bureaucrat::Bureaucrat(Bureaucrat const &other) :
	name(other.name), grade(other.grade)
{
	*this = other;
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->name);
}

int const			&Bureaucrat::getGrade(void) const
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

void				Bureaucrat::signForm(Form &form)
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

void				Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception &e)
	{
		std::cout << *this << " cannot execute " << form <<
			" because " << e.what() << std::endl;
	}
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &bur)
{
	os << "Bureaucrat " << bur.getName() << " (Grade " << bur.getGrade() << ")";
	return (os);
}

const char			*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high to create or upgrade");
}

const char			*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low to create or downgrade");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(
	Bureaucrat::GradeTooHighException const &other)
{
	*this = other;
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(
	Bureaucrat::GradeTooHighException const &other)
{
	(void)other;
	return (*this);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
	Bureaucrat::GradeTooLowException const &other)
{
	*this = other;
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(
	Bureaucrat::GradeTooLowException const &other)
{
	(void)other;
	return (*this);
}
