#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <cstring>

void	readstream(std::istream& is)
{
	std::string		tmp;

	while (std::getline(is, tmp))
	{
		std::cout << tmp;
		if (!is.eof())
			std::cout << std::endl;
	}
}

void	readfile(const std::string& filename)
{
	std::ifstream	ifs(filename.c_str());

	if (ifs.is_open())
	{
		readstream(ifs);
		ifs.close();
	}
	else
		std::cout << "cato9tails: " + filename + ": " +
			std::strerror(errno) << std::endl;
}

int		main(int ac, char **av)
{
	int	i = 0;

	if (ac < 2)
		readstream(std::cin);
	else
		while (++i < ac)
			readfile(std::string(av[i]));
	return (0);
}
