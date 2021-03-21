#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent {
private:
	std::string	type;
public:
	ZombieEvent();
	~ZombieEvent();
	void		setZombieType(const std::string& type);
	Zombie*		newZombie(const std::string& name);
	Zombie*		randomChump(void);
};

#endif
