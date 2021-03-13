#include "Squad.hpp"

Squad::Squad()
{
	this->marines = NULL;
	this->count = 0;
}

Squad::~Squad()
{
	int		i = -1;

	if (this->marines != NULL)
	{
		while (++i < this->count)
			delete (this->marines[i]);
		delete[] (this->marines);
	}
}

Squad::Squad(Squad const &other)
{
	this->marines = NULL;
	this->count = 0;
	*this = other;
}

Squad			&Squad::operator=(Squad const &other)
{
	int		i = -1;

	if (this == &other)
		return (*this);
	if (this->marines != NULL)
	{
		while (++i < count)
			delete (this->marines[i]);
		delete[] (this->marines);
		this->marines = NULL;
		this->count = 0;
	}
	i = -1;
	while (other.marines != NULL && ++i < other.count)
		this->push(other.getUnit(i)->clone());
	return (*this);
}

int				Squad::getCount(void) const
{
	return (this->count);
}

ISpaceMarine 	*Squad::getUnit(int id) const
{
	if (id >= 0 && id < count)
		return (marines[id]);
	return (NULL);
}

int				Squad::push(ISpaceMarine *unit)
{
	ISpaceMarine	**dup;
	int				i;

	if (unit == NULL)
		return (this->count);
	if (this->marines == NULL)
	{
		this->count = 1;
		this->marines = new ISpaceMarine*[this->count];
		this->marines[0] = unit;
	}
	else
	{
		i = -1;
		while (++i < this->count)
			if (this->marines[i] == unit)
				return (i);
		this->count++;
		dup = new ISpaceMarine*[this->count];
		i = -1;
		while (++i < this->count - 1)
			dup[i] = this->marines[i];
		dup[i] = unit;
		delete[] (this->marines);
		this->marines = dup;
	}
	return (this->count);
}
