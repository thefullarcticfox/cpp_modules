#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(std::string const &name) : name(name)
{
	std::cout << "Some random victim called " << this->name <<
		" just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name <<
		" just died for no apparent reason!" << std::endl;
}

Victim::Victim(Victim const &other)
{
	*this = other;
}

Victim				&Victim::operator=(Victim const &other)
{
	this->name = other.name;
	return (*this);
}

std::string const	&Victim::getname(void) const
{
	return (this->name);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!" <<
		std::endl;
}

std::ostream		&operator<<(std::ostream &os, Victim const &vict)
{
	os << "I'm " << vict.getname() << " and I like otters!" << std::endl;
	return (os);
}
