#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int		i = -1;

	this->known = 0;
	while (++i < 4)
		this->storage[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	int		i = -1;

	while (++i < 4)
		delete (this->storage[i]);
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	int		i = -1;

	this->known = 0;
	while (++i < 4)
		this->storage[i] = NULL;
	*this = other;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	int		i = -1;

	if (this == &other)
		return (*this);
	while (++i < 4)
	{
		delete (this->storage[i]);
		this->storage[i] = NULL;
		this->known = 0;
	}
	i = -1;
	while (++i < other.known && other.storage[i])
		this->learnMateria(other.storage[i]->clone());
	return (*this);
}

void			MateriaSource::learnMateria(AMateria *materia)
{
	int		i = -1;

	if (this->known == 4 || materia == NULL)
		return ;
	while (++i < this->known)
		if (this->storage[i] == materia)
			return ;
	this->storage[this->known] = materia;
	this->known++;
}

AMateria*		MateriaSource::createMateria(std::string const &type)
{
	int		i = -1;

	if (this->known == 0)
		return (NULL);
	while (++i < this->known && this->storage[i] != NULL)
		if (this->storage[i]->getType().compare(type) == 0)
			return (this->storage[i]->clone());
	return (NULL);
}
