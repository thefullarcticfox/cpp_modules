#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::~DeepCoreMiner()
{
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &other)
{
	*this = other;
}

DeepCoreMiner &DeepCoreMiner::operator=(DeepCoreMiner const &other)
{
	(void)other;
	return (*this);
}

void	DeepCoreMiner::mine(IAsteroid *asteroid)
{
	if (asteroid != NULL)
		std::cout << "* mining deep... got " << asteroid->beMined(this) <<
			"! *" << std::endl;
}
