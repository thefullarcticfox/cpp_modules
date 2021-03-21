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
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	void			execute(const Bureaucrat& executor) const;
};

#endif
