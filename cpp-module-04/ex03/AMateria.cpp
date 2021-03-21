#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const std::string& type) : type(type)
{
	this->_xp = 0;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria&			AMateria::operator=(const AMateria& other)
{
	this->_xp = other._xp;
	this->type = other.type;
	return (*this);
}

const std::string&	AMateria::getType(void) const
{
	return (this->type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}
