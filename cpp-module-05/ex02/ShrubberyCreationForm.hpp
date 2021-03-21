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
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	void			execute(const Bureaucrat& executor) const;

	class FileWriteFailureException : public std::exception {
	public:
		FileWriteFailureException();
		virtual ~FileWriteFailureException() throw();
		FileWriteFailureException(const FileWriteFailureException& other);
		FileWriteFailureException&	operator=(const FileWriteFailureException& other);

		virtual const char*		what() const throw();
	};
};

#endif
