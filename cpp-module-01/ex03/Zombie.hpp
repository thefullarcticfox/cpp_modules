#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {
private:
	std::string	name;
	std::string	type;
	int			hp;
	static
	std::string	randomname(int len);
public:
	Zombie();
	Zombie(const std::string& name, const std::string& type);
	Zombie(const std::string& type);
	~Zombie();
	void		announce(void);
	bool		attackbase(void);
	void		settype(const std::string& type);
};

#endif
