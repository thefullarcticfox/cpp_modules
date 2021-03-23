#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
private:
	static const int			qcount = 8;
	static const std::string	quotes[qcount];
protected:
	static const int	init_hp = 100;
	static const int	init_maxhp = 100;
	static const int	init_ep = 100;
	static const int	init_maxep = 100;
	static const int	init_mdmg = 30;
	static const int	init_rdmg = 20;
	static const int	init_armor = 5;
	FragTrap();
public:
	FragTrap(const std::string& name);
	virtual	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap&	operator=(const FragTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
	void		vaulthunter_dot_exe(const std::string& target);
};

#endif
