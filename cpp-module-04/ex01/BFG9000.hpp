#ifndef BFG9000_HPP
# define BFG9000_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"

class BFG9000 : public AWeapon {
public:
	BFG9000();
	virtual ~BFG9000();
	BFG9000(const BFG9000& other);
	BFG9000&	operator=(const BFG9000& other);

	void		attack(void) const;
};

#endif
