#include "Contact.hpp"

Contact::Contact()
{
	fields[0] = "first name";
	fields[1] = "last name";
	fields[2] = "nickname";
	fields[3] = "login";
	fields[4] = "postal address";
	fields[5] = "email address";
	fields[6] = "phone number";
	fields[7] = "birthday date";
	fields[8] = "favorite meal";
	fields[9] = "underwear color";
	fields[10] = "darkest secret";
}

Contact::~Contact()
{
}

std::string	Contact::getfirst(void)
{
	return (this->data[0]);
}

std::string	Contact::getlast(void)
{
	return (this->data[1]);
}

std::string	Contact::getnick(void)
{
	return (this->data[2]);
}

bool	Contact::setinfo(void)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		std::cout << "enter " << fields[i] << ": ";
		std::getline(std::cin, data[i]);
	}
	i = -1;
	while (++i < 11)
		if (!data[i].empty())
			return (true);
	return (false);
}

void	Contact::printinfo(void)
{
	int		i;

	i = -1;
	while (++i < 11)
		std::cout << std::setw(17) <<
			fields[i] << ": " << data[i] << std::endl;
}
