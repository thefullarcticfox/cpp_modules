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
	Sorcerer(const std::string& name, const std::string& title);
	virtual ~Sorcerer();
	Sorcerer(const Sorcerer& other);
	Sorcerer&	operator=(const Sorcerer& other);

	const std::string&	getname(void) const;
	const std::string&	gettitle(void) const;
	void				polymorph(const Victim& vict) const;
};

std::ostream&			operator<<(std::ostream& os, const Sorcerer& src);

#endif
