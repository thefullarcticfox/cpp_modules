#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
{
	this->intern = NULL;
	this->signer = NULL;
	this->executor = NULL;
}

OfficeBlock::OfficeBlock(Intern& intern,
	Bureaucrat& signer, Bureaucrat& executor)
{
	this->intern = &intern;
	this->signer = &signer;
	this->executor = &executor;
}

OfficeBlock::~OfficeBlock()
{
}

OfficeBlock::OfficeBlock(const OfficeBlock& other)
{
	*this = other;
}

OfficeBlock&	OfficeBlock::operator=(const OfficeBlock& other)
{
	this->intern = other.intern;
	this->signer = other.signer;
	this->executor = other.executor;
	return (*this);
}

void			OfficeBlock::setIntern(Intern& intern)
{
	this->intern = &intern;
}

void			OfficeBlock::setSigner(Bureaucrat& signer)
{
	this->signer = &signer;
}

void			OfficeBlock::setExecutor(Bureaucrat& executor)
{
	this->executor = &executor;
}

void		OfficeBlock::doBureaucracy(const std::string& form,
	const std::string& target)
{
	Form*	formptr = NULL;

	if (this->intern == NULL || this->signer == NULL ||
		this->executor == NULL)
		throw (OfficeBlock::MemberMissingException());
	try
	{
		formptr = intern->makeForm(form, target);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << ": " << form << std::endl;
		return ;
	}
	try
	{
		this->signer->signForm(*formptr);
	}
	catch(const std::exception& e)
	{
		std::cout << *(this->signer) << " cannot sign " << *formptr <<
			" because " << e.what() << std::endl;
		delete (formptr);
		return ;
	}
	try
	{
		executor->executeForm(*formptr);
	}
	catch (const std::exception& e)
	{
		std::cout << *(this->executor) << " cannot execute " << *formptr <<
			" because " << e.what() << std::endl;
		delete (formptr);
		return ;
	}
	delete (formptr);
}

const char*	OfficeBlock::MemberMissingException::what() const throw()
{
	return ("Office block member is missing");
}

OfficeBlock::MemberMissingException::MemberMissingException() {}

OfficeBlock::MemberMissingException::~MemberMissingException() throw() {}

OfficeBlock::MemberMissingException::MemberMissingException(
	const OfficeBlock::MemberMissingException& other)
{
	*this = other;
}

OfficeBlock::MemberMissingException&	OfficeBlock::MemberMissingException::operator=(
	const OfficeBlock::MemberMissingException& other)
{
	(void)other;
	return (*this);
}
