#include <cstdlib>
#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	n = 0;
}

Phonebook::~Phonebook()
{
}

std::string	Phonebook::fieldfrmt(std::string field)
{
	if (field.length() > 10)
		field = field.substr(0, 9) + ".";
	return (field);
}

void		Phonebook::add(void)
{
	if (n >= 8)
	{
		std::cout << "Error: can't add more than 8 contacts." << std::endl;
		return ;
	}
	if (!contact[n].setinfo())
		std::cout << "Error: empty contact." << std::endl;
	else
		n++;
}

void		Phonebook::search(void)
{
	std::string	tmp;
	int			i;

	if (n == 0)
	{
		std::cout << "Error: no contacts to search." << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index" << "|" <<
				std::setw(10) << "firstname" << "|" <<
				std::setw(10) << "lastname" << "|" <<
				std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	i = -1;
	while (++i < n)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << fieldfrmt(contact[i].getfirst()) << "|";
		std::cout << std::setw(10) << fieldfrmt(contact[i].getlast()) << "|";
		std::cout << std::setw(10) << fieldfrmt(contact[i].getnick()) << "|";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "enter index [" << 1 << "-" << n << "]: ";
	std::getline(std::cin, tmp);
	if ((tmp.find_first_not_of(" 0123456789") != std::string::npos) ||
		((i = std::atoi(tmp.c_str()) - 1) && (i < 0 || i >= n)))
	{
		std::cout << "Error: bad index." << std::endl;
		return ;
	}
	contact[i].printinfo();
}
