#include "Brain.hpp"

Brain::Brain()
{
	size = 0;
}

Brain::~Brain()
{
}

std::string		Brain::identify(void) const
{
	std::stringstream	ss;

	ss << "0x" << std::uppercase << std::hex << (const unsigned long int)this;
	return (ss.str());
}
