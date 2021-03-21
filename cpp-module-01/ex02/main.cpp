#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ZombieEvent.hpp"
#define ZCOUNT 20

std::string		randomspecialname(int num)
{
	std::string		name[10] = { "Gaspar", "Johnny", "Olivier", "Eli",
		"Stefan", "Simon", "Charlie", "Edmont", "Edgar", "Brian"};

	num %= 10;
	return (name[num]);
}

void			nukezombienest(void)
{
	Zombie			znest[ZCOUNT];
	int				i = -1;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombie nest located <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	while (++i < ZCOUNT)
	{
		znest[i].settype("Nest");
		znest[i].announce();
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Nuke launched <<<" << std::endl;
	std::cout << ">>> Direct hit on zombie nest <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int				main(void)
{
	ZombieEvent		infected;
	ZombieEvent		tanks;
	Zombie*			zhorde[ZCOUNT];
	int				i = -1;
	int				j = 0;

	std::srand(std::time(NULL));
	infected.setZombieType("Infected");
	tanks.setZombieType("Tank");
	std::cout << ">>> A wave of zombies approaching <<<" << std::endl;
	std::cout << ">>> Searching for their nest <<<" << std::endl;
	while (++i < ZCOUNT)
		if (std::rand() % 10)
			zhorde[i] = infected.randomChump();
		else
		{
			zhorde[i] = tanks.newZombie(randomspecialname(j++));
			zhorde[i]->announce();
		}
	nukezombienest();
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombie nest destroyed <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombies have reached the base <<<" << std::endl;
	std::cout << ">>> Turrets activated <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	i = 0;
	while (i < ZCOUNT)
	{
		j = rand() % ZCOUNT;
		if (zhorde[j] != NULL && zhorde[j]->attackbase())
		{
			delete (zhorde[j]);
			zhorde[j] = NULL;
			i++;
		}
	}
	std::cout << ">>> All zombies have been killed <<<" << std::endl;
	return (0);
}
