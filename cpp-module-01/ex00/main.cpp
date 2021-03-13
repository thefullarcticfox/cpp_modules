#include <iostream>
#include <ctime>
#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	Pony	*pony = new Pony("Heapony");

	pony->live();
	pony->printinfo();
	delete (pony);
}

void	ponyOnTheStack(void)
{
	Pony	pony("Stackpony");

	pony.live();
	pony.printinfo();
}

int		main(void)
{
	std::srand(std::time(NULL));
	ponyOnTheHeap();
	std::cout <<
		"-------------------------------------------------" << std::endl;
	ponyOnTheStack();
	return (0);
}
