#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public Form {
private:
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

	void			execute(Bureaucrat const &executor) const;

	class FileWriteFailureException : public std::exception {
	public:
		FileWriteFailureException();
		virtual ~FileWriteFailureException() throw();
		FileWriteFailureException(FileWriteFailureException const &other);
		FileWriteFailureException &operator=(FileWriteFailureException const &other);

		virtual const char	*what() const throw();
	};
};

#endif
