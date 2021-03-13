#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant();
	virtual ~SuperMutant();
	SuperMutant(SuperMutant const &other);
	SuperMutant &operator=(SuperMutant const &other);

	void	takeDamage(int dmg);
};

#endif
