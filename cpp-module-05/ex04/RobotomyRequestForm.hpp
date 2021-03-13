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
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	void			execute(Bureaucrat const &executor) const;
};

#endif
