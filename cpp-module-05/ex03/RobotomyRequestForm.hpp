#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	void			execute(const Bureaucrat& executor) const;
};

#endif
