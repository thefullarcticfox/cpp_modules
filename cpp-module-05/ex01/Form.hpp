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
	Form(std::string const &name, int const &signgrade, int const execgrade);
	virtual ~Form();
	Form(Form const &other);
	Form &operator=(Form const &other);

	std::string const	&getName(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	bool				isSigned(void) const;
	void				beSigned(Bureaucrat const &bur);

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
};

std::ostream			&operator<<(std::ostream &os, Form const &bur);

#endif
