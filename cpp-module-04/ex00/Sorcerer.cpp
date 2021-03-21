#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(const std::string& name, const std::string& title) :
	name(name), title(title)
{
	std::cout << this->name << ", " << this->title << ", is born!" <<
		std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name << ", " << this->title << ", is dead. " <<
		"Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& other)
{
	*this = other;
}

Sorcerer&			Sorcerer::operator=(const Sorcerer& other)
{
	this->name = other.name;
	this->title = other.title;
	return (*this);
}

const std::string&	Sorcerer::getname(void) const
{
	return (this->name);
}

const std::string&	Sorcerer::gettitle(void) const
{
	return (this->title);
}

void				Sorcerer::polymorph(const Victim& vict) const
{
	vict.getPolymorphed();
}

std::ostream&		operator<<(std::ostream& os, const Sorcerer& src)
{
	os << "I am " << src.getname() << ", " << src.gettitle() <<
		", and I like ponies!" << std::endl;
	return (os);
}
