#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer {
private:
	std::string			name;
	std::string			title;
	Sorcerer();
public:
	Sorcerer(std::string const &name, std::string const &title);
	virtual ~Sorcerer();
	Sorcerer(Sorcerer const &other);
	Sorcerer &operator=(Sorcerer const &other);

	std::string const	&getname(void) const;
	std::string const	&gettitle(void) const;
	void				polymorph(Victim const &vict) const;
};

std::ostream			&operator<<(std::ostream &os, Sorcerer const &src);

#endif
