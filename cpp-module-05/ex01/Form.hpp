#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
class Form;
# include "Bureaucrat.hpp"

class Form {
private:
	std::string const	name;
	bool				_issigned;
	int const			signgrade;
	int const			execgrade;
	Form();
public:
	Form(const std::string& name, int signgrade, int const execgrade);
	virtual ~Form();
	Form(const Form& other);
	Form&				operator=(const Form& other);

	const std::string&	getName(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	bool				isSigned(void) const;
	void				beSigned(const Bureaucrat& bur);

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(const GradeTooHighException& other);
		GradeTooHighException&	operator=(const GradeTooHighException& other);

		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(const GradeTooLowException& other);
		GradeTooLowException&	operator=(const GradeTooLowException& other);

		virtual const char*	what() const throw();
	};
	class AlreadySignedException : public std::exception {
	public:
		AlreadySignedException();
		virtual ~AlreadySignedException() throw();
		AlreadySignedException(const AlreadySignedException& other);
		AlreadySignedException&	operator=(const AlreadySignedException& other);

		virtual const char*	what() const throw();
	};
};

std::ostream&		operator<<(std::ostream& os, const Form& bur);

#endif
