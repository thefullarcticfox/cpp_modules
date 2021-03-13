#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"

class Squad : public ISquad {
private:
	ISpaceMarine	**marines;
	int				count;
public:
	Squad();
	virtual ~Squad();
	Squad(Squad const &other);
	Squad &operator=(Squad const &other);

	int				getCount(void) const;
	ISpaceMarine 	*getUnit(int number) const;
	int				push(ISpaceMarine *unit);
};

#endif
