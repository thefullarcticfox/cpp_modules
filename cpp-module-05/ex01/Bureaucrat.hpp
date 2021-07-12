#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
class Bureaucrat;
# include "Form.hpp"

class Bureaucrat {
private:
	const std::string	name;
	int					grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string& name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);

	const std::string&	getName(void) const;
	int					getGrade(void) const;
	void				upGrade(void);
	void				downGrade(void);
	void				signForm(Form& form);

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
};

std::ostream&		operator<<(std::ostream& os, const Bureaucrat& bur);

#endif
