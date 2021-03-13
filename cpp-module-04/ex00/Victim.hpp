#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>

class Victim {
private:
	Victim();
protected:
	std::string			name;
public:
	Victim(std::string const &name);
	virtual ~Victim();
	Victim(Victim const &other);
	Victim &operator=(Victim const &other);

	std::string const	&getname(void) const;
	virtual void		getPolymorphed(void) const;
};

std::ostream			&operator<<(std::ostream &os, Victim const &vict);

#endif
