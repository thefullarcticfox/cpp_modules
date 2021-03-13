#include <iostream>
#include <string>

void	memoryLeak()
{
	std::string		*panther = new std::string("String panther");

	std::cout << *panther << std::endl;
	delete (panther);
}

/*
**	clang++ -Wall -Wextra -Werror ex01.cpp
**	leaks --atExit -- ./a.out
*/

int		main(void)
{
	memoryLeak();
	return (0);
}
