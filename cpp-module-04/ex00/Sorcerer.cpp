#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string const &name, std::string const &title) :
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

Sorcerer::Sorcerer(Sorcerer const &other)
{
	*this = other;
}

Sorcerer			&Sorcerer::operator=(Sorcerer const &other)
{
	this->name = other.name;
	this->title = other.title;
	return (*this);
}

std::string const	&Sorcerer::getname(void) const
{
	return (this->name);
}

std::string const	&Sorcerer::gettitle(void) const
{
	return (this->title);
}

void				Sorcerer::polymorph(Victim const &vict) const
{
	vict.getPolymorphed();
}

std::ostream		&operator<<(std::ostream &os, Sorcerer const &src)
{
	os << "I am " << src.getname() << ", " << src.gettitle() <<
		", and I like ponies!" << std::endl;
	return (os);
}
