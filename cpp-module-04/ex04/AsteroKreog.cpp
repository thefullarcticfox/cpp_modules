#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog() : name("Asteroid")
{
}

AsteroKreog::~AsteroKreog()
{
}

AsteroKreog::AsteroKreog(AsteroKreog const &other)
{
	*this = other;
}

AsteroKreog		&AsteroKreog::operator=(AsteroKreog const &other)
{
	this->name = other.name;
	return (*this);
}

std::string		AsteroKreog::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return ("Dragonite");
}

std::string		AsteroKreog::beMined(StripMiner *laser) const
{
	(void)laser;
	return ("Flavium");
}

std::string		AsteroKreog::getName(void) const
{
	return (this->name);
}
