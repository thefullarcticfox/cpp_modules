#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
class NinjaTrap;
# include "NinjaTrap.hpp"

class SuperTrap : public virtual FragTrap, public virtual NinjaTrap {
private:
	SuperTrap();
public:
	SuperTrap(const std::string& name);
	virtual	~SuperTrap();
	SuperTrap(const SuperTrap& other);
	SuperTrap&	operator=(const SuperTrap& other);

	void		rangedAttack(const std::string& target);
	void		meleeAttack(const std::string& target);
};

#endif
