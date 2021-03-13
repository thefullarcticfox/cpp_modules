#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Intern {
private:
	Form	*makePresidentialPardon(std::string const &target);
	Form	*makeRobotomyRequest(std::string const &target);
	Form	*makeShrubberyCreation(std::string const &target);
public:
	Intern();
	virtual ~Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);

	Form	*makeForm(std::string const &form, std::string const &target);

	class FormNotFoundException : public std::exception {
	public:
		FormNotFoundException();
		virtual ~FormNotFoundException() throw();
		FormNotFoundException(FormNotFoundException const &other);
		FormNotFoundException &operator=(FormNotFoundException const &other);

		virtual const char	*what() const throw();
	};
};

#endif
