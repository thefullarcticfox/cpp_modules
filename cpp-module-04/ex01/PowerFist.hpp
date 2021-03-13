#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist();
	virtual ~PowerFist();
	PowerFist(PowerFist const &other);
	PowerFist &operator=(PowerFist const &other);

	void			attack(void) const;
};

#endif
