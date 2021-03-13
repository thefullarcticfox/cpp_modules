#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::~StripMiner()
{
}

StripMiner::StripMiner(StripMiner const &other)
{
	*this = other;
}

StripMiner &StripMiner::operator=(StripMiner const &other)
{
	(void)other;
	return (*this);
}

void	StripMiner::mine(IAsteroid *asteroid)
{
	if (asteroid != NULL)
		std::cout << "* strip mining... got " << asteroid->beMined(this) <<
			"! *" << std::endl;
}
