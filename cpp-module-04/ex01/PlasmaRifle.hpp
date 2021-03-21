#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	PlasmaRifle(const PlasmaRifle& other);
	PlasmaRifle&	operator=(const PlasmaRifle& other);

	void			attack(void) const;
};

#endif
