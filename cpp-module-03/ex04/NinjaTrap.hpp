#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {
protected:
	NinjaTrap();
public:
	NinjaTrap(std::string const &name);
	virtual	~NinjaTrap();
	NinjaTrap(NinjaTrap const &other);
	NinjaTrap &operator=(NinjaTrap const &other);

	void			rangedAttack(std::string const &target);
	void			meleeAttack(std::string const &target);
	void			ninjaShoebox(ClapTrap &trap);
	void			ninjaShoebox(FragTrap &trap);
	void			ninjaShoebox(ScavTrap &trap);
	void			ninjaShoebox(NinjaTrap &trap);
};

#endif
