#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant();
	virtual ~SuperMutant();
	SuperMutant(const SuperMutant& other);
	SuperMutant&	operator=(const SuperMutant& other);

	void	takeDamage(int dmg);
};

#endif
