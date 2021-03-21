#ifndef DEATHCLAW_HPP
# define DEATHCLAW_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class DeathClaw : public Enemy {
public:
	DeathClaw();
	virtual ~DeathClaw();
	DeathClaw(const DeathClaw& other);
	DeathClaw&	operator=(const DeathClaw& other);

	void		takeDamage(int dmg);
};

#endif
