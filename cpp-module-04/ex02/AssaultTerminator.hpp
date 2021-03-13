#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
public:
	AssaultTerminator();
	virtual ~AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &other);
	AssaultTerminator &operator=(AssaultTerminator const &other);

	ISpaceMarine	*clone(void) const;
	void			battleCry(void) const;
	void			rangedAttack(void) const;
	void			meleeAttack(void) const;
};

#endif
