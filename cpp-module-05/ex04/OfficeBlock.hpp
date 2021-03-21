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
	Intern*			intern;
	Bureaucrat*		signer;
	Bureaucrat*		executor;
public:
	OfficeBlock();
	OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor);
	virtual ~OfficeBlock();
	OfficeBlock(const OfficeBlock& other);
	OfficeBlock&	operator=(const OfficeBlock& other);

	void			setIntern(Intern& intern);
	void			setSigner(Bureaucrat& signer);
	void			setExecutor(Bureaucrat& executor);
	void			doBureaucracy(const std::string& form,
		const std::string& target);

	class MemberMissingException : public std::exception {
	public:
		MemberMissingException();
		virtual ~MemberMissingException() throw();
		MemberMissingException(const MemberMissingException& other);
		MemberMissingException&	operator=(const MemberMissingException& other);

		virtual const char*		what() const throw();
	};
};

#endif
