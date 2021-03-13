#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
private:
	std::string	fields[11];
	std::string	data[11];
public:
	Contact();
	~Contact();
	std::string	getfirst(void);
	std::string	getlast(void);
	std::string	getnick(void);
	bool		setinfo(void);
	void		printinfo(void);
};

#endif
