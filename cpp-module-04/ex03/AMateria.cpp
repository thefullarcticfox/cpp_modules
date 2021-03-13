#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
	this->_xp = 0;
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &other)
{
	*this = other;
}

AMateria			&AMateria::operator=(AMateria const &other)
{
	this->_xp = other._xp;
	this->type = other.type;
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter &target)
{
	(void)target;
	this->_xp += 10;
}
