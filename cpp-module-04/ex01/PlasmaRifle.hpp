#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &other);
	PlasmaRifle &operator=(PlasmaRifle const &other);

	void			attack(void) const;
};

#endif
