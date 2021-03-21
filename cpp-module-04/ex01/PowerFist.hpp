#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist();
	virtual ~PowerFist();
	PowerFist(const PowerFist& other);
	PowerFist&	operator=(const PowerFist& other);

	void		attack(void) const;
};

#endif
