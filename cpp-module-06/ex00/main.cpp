#include <iostream>
#include "Converter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "usage: ./convert <value>" << std::endl;
	else
	{
		Converter	c(av[1]);
		std::cout << c;
	}
	return (0);
}
