#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	int		i = -1;

	count = N;
	if (count > 0)
	{
		zombies = new Zombie[this->count];
		while (++i < count)
			zombies[i].settype("Horde");
		this->announce();
	}
}

ZombieHorde::ZombieHorde(std::string type, int N)
{
	int		i = -1;

	count = N;
	if (count > 0)
	{
		zombies = new Zombie[this->count];
		while (++i < count)
			zombies[i].settype(type);
		this->announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete[] (zombies);
}

void		ZombieHorde::announce(void)
{
	int		i = -1;

	while (++i < count)
		zombies[i].announce();
}
