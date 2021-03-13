#include "Phonebook.hpp"

int		main(void)
{
	Phonebook	pb;
	std::string	cmd;

	while (true)
	{
		std::cout << "phonebook$ ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			break ;
		else if (cmd.compare("ADD") == 0)
			pb.add();
		else if (cmd.compare("SEARCH") == 0)
			pb.search();
		else
			continue ;
	}
	return (0);
}
