#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Rabbit.hpp"

int		main(void)
{
	std::cout << ">>>>>> Calling constructors" << std::endl;
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");
	Rabbit		jacob("Jacob");

	std::cout << std::endl << ">>>>>> Calling << overloads" << std::endl;
	std::cout << robert << jim << joe << jacob;

	std::cout << std::endl << ">>>>>> Calling Victim::getPolymorphed" <<
		std::endl;
	jim.getPolymorphed();
	joe.getPolymorphed();
	jacob.getPolymorphed();

	std::cout << std::endl << ">>>>>> Calling Sorcerer::polymorph" << std::endl;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(jacob);

	std::cout << std::endl << ">>>>>> Calling destructors" << std::endl;
	return (0);
}
