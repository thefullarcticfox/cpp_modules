#include "Peon.hpp"

Peon::Peon() : Victim("peon")
{
}

Peon::Peon(const std::string& name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon& other) : Victim(other.name)
{
	*this = other;
}

Peon&	Peon::operator=(const Peon& other)
{
	this->name = other.name;
	return (*this);
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a pink pony!" <<
		std::endl;
}
