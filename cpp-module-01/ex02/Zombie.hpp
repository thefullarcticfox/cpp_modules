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
	std::string	randomname(int len);
public:
	Zombie();
	Zombie(std::string name, std::string type);
	Zombie(std::string type);
	~Zombie();
	void		announce(void);
	bool		attackbase(void);
	void		settype(std::string type);
};

#endif
