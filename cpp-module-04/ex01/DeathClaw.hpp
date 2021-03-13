#ifndef DEATHCLAW_HPP
# define DEATHCLAW_HPP

# include <iostream>
# include <string>
# include "Enemy.hpp"

class DeathClaw : public Enemy {
public:
	DeathClaw();
	virtual ~DeathClaw();
	DeathClaw(DeathClaw const &other);
	DeathClaw &operator=(DeathClaw const &other);

	void	takeDamage(int dmg);
};

#endif
