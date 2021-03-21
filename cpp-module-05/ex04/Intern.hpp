#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Intern {
private:
	Form*	makePresidentialPardon(const std::string& target);
	Form*	makeRobotomyRequest(const std::string& target);
	Form*	makeShrubberyCreation(const std::string& target);
public:
	Intern();
	virtual ~Intern();
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);

	Form*	makeForm(const std::string& form, const std::string& target);

	class FormNotFoundException : public std::exception {
	public:
		FormNotFoundException();
		virtual ~FormNotFoundException() throw();
		FormNotFoundException(const FormNotFoundException& other);
		FormNotFoundException&	operator=(const FormNotFoundException& other);

		virtual const char*	what() const throw();
	};
};

#endif
