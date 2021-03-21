#include "Victim.hpp"

Victim::Victim()
{
}

Victim::Victim(const std::string& name) : name(name)
{
	std::cout << "Some random victim called " << this->name <<
		" just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name <<
		" just died for no apparent reason!" << std::endl;
}

Victim::Victim(const Victim& other)
{
	*this = other;
}

Victim&				Victim::operator=(const Victim& other)
{
	this->name = other.name;
	return (*this);
}

const std::string&	Victim::getname(void) const
{
	return (this->name);
}

void				Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep!" <<
		std::endl;
}

std::ostream&		operator<<(std::ostream& os, const Victim& vict)
{
	os << "I'm " << vict.getname() << " and I like otters!" << std::endl;
	return (os);
}
