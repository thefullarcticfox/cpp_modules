#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &other)
{
	*this = other;
}

TacticalMarine	&TacticalMarine::operator=(TacticalMarine const &other)
{
	(void)other;
	return (*this);
}

ISpaceMarine	*TacticalMarine::clone(void) const
{
	ISpaceMarine	*unit = new TacticalMarine(*this);
	return (unit);
}

void			TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with a chainsword *" << std::endl;
}
