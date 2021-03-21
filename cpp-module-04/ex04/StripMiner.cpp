#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::~StripMiner()
{
}

StripMiner::StripMiner(const StripMiner& other)
{
	*this = other;
}

StripMiner&	StripMiner::operator=(const StripMiner& other)
{
	(void)other;
	return (*this);
}

void		StripMiner::mine(IAsteroid* asteroid)
{
	if (asteroid != NULL)
		std::cout << "* strip mining... got " << asteroid->beMined(this) <<
			"! *" << std::endl;
}
