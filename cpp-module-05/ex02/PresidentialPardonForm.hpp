#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	void			execute(Bureaucrat const &executor) const;
};

#endif
