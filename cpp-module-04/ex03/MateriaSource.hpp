#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	int			known;
	AMateria	*storage[4];
public:
	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);

	void		learnMateria(AMateria *materia);
	AMateria*	createMateria(std::string const &type);
};

#endif
