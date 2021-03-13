#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid() : name("Comet")
{
}

KoalaSteroid::~KoalaSteroid()
{
}

KoalaSteroid::KoalaSteroid(KoalaSteroid const &other)
{
	*this = other;
}

KoalaSteroid	&KoalaSteroid::operator=(KoalaSteroid const &other)
{
	this->name = other.name;
	return (*this);
}

std::string		KoalaSteroid::beMined(DeepCoreMiner *laser) const
{
	(void)laser;
	return ("Meium");
}

std::string		KoalaSteroid::beMined(StripMiner *laser) const
{
	(void)laser;
	return ("Tartarite");
}

std::string		KoalaSteroid::getName(void) const
{
	return (this->name);
}
