#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
class Form;
# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	name;
	bool				_issigned;
	const int			signgrade;
	const int			execgrade;
	std::string 		target;
	Form();
public:
	Form(const std::string& name, int signgrade, const int execgrade);
	virtual ~Form();
	Form(const Form& other);
	Form&				operator=(const Form& other);

	const std::string&	getName(void) const;
	const std::string&	getTarget(void) const;
	void				setTarget(const std::string& target);
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	bool				isSigned(void) const;
	void				beSigned(const Bureaucrat& bur);
	virtual void		execute(const Bureaucrat& executor) const = 0;

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
	class GradeTooLowToSignException : public std::exception {
	public:
		GradeTooLowToSignException();
		virtual ~GradeTooLowToSignException() throw();
		GradeTooLowToSignException(const GradeTooLowToSignException& other);
		GradeTooLowToSignException&	operator=(const GradeTooLowToSignException& other);

		virtual const char*	what() const throw();
	};
	class GradeTooLowToExecuteException : public std::exception {
	public:
		GradeTooLowToExecuteException();
		virtual ~GradeTooLowToExecuteException() throw();
		GradeTooLowToExecuteException(const GradeTooLowToExecuteException& other);
		GradeTooLowToExecuteException&	operator=(const GradeTooLowToExecuteException& other);

		virtual const char*	what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		NotSignedException();
		virtual ~NotSignedException() throw();
		NotSignedException(const NotSignedException& other);
		NotSignedException&	operator=(const NotSignedException& other);

		virtual const char*	what() const throw();
	};
};

std::ostream&		operator<<(std::ostream& os, const Form& bur);

#endif
