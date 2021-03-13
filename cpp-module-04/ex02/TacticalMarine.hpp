#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
	TacticalMarine();
	virtual ~TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	TacticalMarine &operator=(TacticalMarine const &other);

	ISpaceMarine	*clone(void) const;
	void			battleCry(void) const;
	void			rangedAttack(void) const;
	void			meleeAttack(void) const;
};

#endif
