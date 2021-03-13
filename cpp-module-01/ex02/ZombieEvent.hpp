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
	void		setZombieType(std::string type);
	Zombie		*newZombie(std::string name);
	Zombie		*randomChump(void);
};

#endif
