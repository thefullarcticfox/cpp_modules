#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

class OfficeBlock {
private:
	Intern			*intern;
	Bureaucrat		*signer;
	Bureaucrat		*executor;
public:
	OfficeBlock();
	OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executor);
	virtual ~OfficeBlock();
	OfficeBlock(OfficeBlock const &other);
	OfficeBlock &operator=(OfficeBlock const &other);

	void			setIntern(Intern &intern);
	void			setSigner(Bureaucrat &signer);
	void			setExecutor(Bureaucrat &executor);
	void			doBureaucracy(std::string const &form,
		std::string const &target);

	class MemberMissingException : public std::exception {
	public:
		MemberMissingException();
		virtual ~MemberMissingException() throw();
		MemberMissingException(MemberMissingException const &other);
		MemberMissingException &operator=(MemberMissingException const &other);

		virtual const char	*what() const throw();
	};
};

#endif
