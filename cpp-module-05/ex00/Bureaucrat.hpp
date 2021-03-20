#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
private:
	std::string const	name;
	int					grade;
	Bureaucrat();
public:
	Bureaucrat(std::string const &name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const	&getName(void) const;
	int const			&getGrade(void) const;
	void				upGrade(void);
	void				downGrade(void);

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
};

std::ostream			&operator<<(std::ostream &os, Bureaucrat const &bur);

#endif
