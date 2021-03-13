#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Phonebook {
private:
	int			n;
	Contact		contact[8];
	std::string	fieldfrmt(std::string field);
public:
	Phonebook();
	~Phonebook();
	void		add(void);
	void		search(void);
};

#endif
