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
	Victim(const std::string& name);
	virtual ~Victim();
	Victim(const Victim& other);
	Victim&		operator=(const Victim& other);

	const std::string&	getname(void) const;
	virtual void		getPolymorphed(void) const;
};

std::ostream&			operator<<(std::ostream& os, const Victim& vict);

#endif
