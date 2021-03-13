#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &other) : AMateria("ice")
{
	*this = other;
}

Ice 		&Ice::operator=(Ice const &other)
{
	AMateria::operator=(other);
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	AMateria	*dup = new Ice(*this);
	return (dup);
}

void		Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<
		std::endl;
}
