#include "BFG9000.hpp"

BFG9000::BFG9000() : AWeapon("BFG-9000", 40, 9000)
{
}

BFG9000::~BFG9000()
{
}

BFG9000::BFG9000(const BFG9000& other) : AWeapon("BFG-9000", 40, 9000)
{
	*this = other;
}

BFG9000&		BFG9000::operator=(const BFG9000& other)
{
	AWeapon::operator=(other);
	return (*this);
}

void			BFG9000::attack(void) const
{
	std::cout << "* psshhhhputsbum BAAAAAAAAAAAAAAANG! *" << std::endl;
}
