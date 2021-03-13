#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const &name) : name(name)
{
	int		i = -1;

	while (++i < 4)
		this->inventory[i] = NULL;
	this->equipped = 0;
}

Character::~Character()
{
	int		i = -1;

	while (++i < this->equipped)
		delete (this->inventory[i]);
}

Character::Character(Character const &other)
{
	int		i = -1;

	while (++i < 4)
		this->inventory[i] = NULL;
	this->equipped = 0;
	*this = other;
}

Character			&Character::operator=(Character const &other)
{
	int		i = -1;

	if (this == &other)
		return (*this);
	this->name = other.name;
	while (++i < 4)
	{
		delete (this->inventory[i]);
		this->inventory[i] = NULL;
		this->equipped = 0;
	}
	i = -1;
	while (++i < other.equipped)
		this->equip(other.inventory[i]->clone());
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void				Character::equip(AMateria *m)
{
	int		i = -1;

	if (this->equipped == 4 || m == NULL)
		return ;
	while (++i < this->equipped)
		if (this->inventory[i] == m)
			return ;
	this->inventory[this->equipped] = m;
	this->equipped++;
}

void				Character::unequip(int idx)
{
	int		i = -1;
	int		j = 0;

	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx] = NULL;
	this->equipped--;
	while (++i < 4 && j < this->equipped)
		if (this->inventory[i] != NULL)
			this->inventory[j++] = this->inventory[i];
	while (j < 4)
		this->inventory[j++] = NULL;
}

void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= this->equipped || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}
