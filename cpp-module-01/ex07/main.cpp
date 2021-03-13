#include <iostream>
#include <string>
#include "Replace.hpp"

int		main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Error: not enough arguments" << std::endl <<
					"Usage: filename s1 s2" << std::endl;
	else
		Replace::execute(std::string(av[1]),
					std::string(av[2]), std::string(av[3]));
	return (0);
}
