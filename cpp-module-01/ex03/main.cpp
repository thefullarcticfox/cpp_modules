#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ZombieHorde.hpp"
#define ZCOUNT 20

void			nukezombienest(void)
{
	ZombieHorde		zhnest("Horde Nest", ZCOUNT);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Nuke launched <<<" << std::endl;
	std::cout << ">>> Direct hit on zombie horde nest <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
}

int		main(void)
{
	ZombieHorde	*horde;

	std::srand(std::time(NULL));
	horde = new ZombieHorde(ZCOUNT);
	std::cout << ">>> A wave of zombies approaching <<<" << std::endl;
	std::cout << ">>> Searching for their nest <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombies have reached the base <<<" << std::endl;
	std::cout << ">>> Turrets activated <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombie nest located <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	nukezombienest();
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombie nest destroyed <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">>> Zombies have reached the base <<<" << std::endl;
	std::cout << ">>> Turrets activated <<<" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	delete (horde);
	std::cout << ">>> All zombies have been killed <<<" << std::endl;
	return (0);
}
