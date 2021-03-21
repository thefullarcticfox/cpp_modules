#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog() : name("Asteroid")
{
}

AsteroKreog::~AsteroKreog()
{
}

AsteroKreog::AsteroKreog(const AsteroKreog& other)
{
	*this = other;
}

AsteroKreog&		AsteroKreog::operator=(const AsteroKreog& other)
{
	this->name = other.name;
	return (*this);
}

std::string			AsteroKreog::beMined(DeepCoreMiner* laser) const
{
	(void)laser;
	return ("Dragonite");
}

std::string			AsteroKreog::beMined(StripMiner* laser) const
{
	(void)laser;
	return ("Flavium");
}

const std::string&	AsteroKreog::getName(void) const
{
	return (this->name);
}
