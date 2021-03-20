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
	std::string 		target;
	Form();
public:
	Form(std::string const &name, int signgrade, int const execgrade);
	virtual ~Form();
	Form(Form const &other);
	Form &operator=(Form const &other);

	std::string const	&getName(void) const;
	std::string const	&getTarget(void) const;
	void				setTarget(std::string const &target);
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	bool				isSigned(void) const;
	void				beSigned(Bureaucrat const &bur);
	virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &other);
		GradeTooHighException &operator=(GradeTooHighException const &other);

		virtual const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &other);
		GradeTooLowException &operator=(GradeTooLowException const &other);

		virtual const char	*what() const throw();
	};
	class AlreadySignedException : public std::exception {
	public:
		AlreadySignedException();
		virtual ~AlreadySignedException() throw();
		AlreadySignedException(AlreadySignedException const &other);
		AlreadySignedException &operator=(AlreadySignedException const &other);

		virtual const char	*what() const throw();
	};
	class GradeTooLowToSignException : public std::exception {
	public:
		GradeTooLowToSignException();
		virtual ~GradeTooLowToSignException() throw();
		GradeTooLowToSignException(GradeTooLowToSignException const &other);
		GradeTooLowToSignException &operator=(GradeTooLowToSignException const &other);

		virtual const char	*what() const throw();
	};
	class GradeTooLowToExecuteException : public std::exception {
	public:
		GradeTooLowToExecuteException();
		virtual ~GradeTooLowToExecuteException() throw();
		GradeTooLowToExecuteException(GradeTooLowToExecuteException const &other);
		GradeTooLowToExecuteException &operator=(GradeTooLowToExecuteException const &other);

		virtual const char	*what() const throw();
	};
	class NotSignedException : public std::exception {
	public:
		NotSignedException();
		virtual ~NotSignedException() throw();
		NotSignedException(NotSignedException const &other);
		NotSignedException &operator=(NotSignedException const &other);

		virtual const char	*what() const throw();
	};
};

std::ostream			&operator<<(std::ostream &os, Form const &bur);

#endif
