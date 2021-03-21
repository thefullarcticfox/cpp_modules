#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::~DeepCoreMiner()
{
}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& other)
{
	*this = other;
}

DeepCoreMiner&	DeepCoreMiner::operator=(const DeepCoreMiner& other)
{
	(void)other;
	return (*this);
}

void			DeepCoreMiner::mine(IAsteroid* asteroid)
{
	if (asteroid != NULL)
		std::cout << "* mining deep... got " << asteroid->beMined(this) <<
			"! *" << std::endl;
}
