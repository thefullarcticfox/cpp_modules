#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int		main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria		*tmp1 = new Cure();
	src->learnMateria(tmp1);
	src->learnMateria(tmp1);
	delete (tmp1);

	ICharacter		*me = new Character("me");

	AMateria		*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter		*bob = new Character("bob");

	me->use(-1, *bob);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

	delete (bob);

	Character		*bob1 = new Character("bob1");
	Character		*bob2 = new Character("bob2");
	tmp = src->createMateria("cure");
	bob2->equip(tmp);
	tmp = src->createMateria("ice");
	bob2->equip(tmp);
	*bob1 = *bob2;

	MateriaSource	*src2 = new MateriaSource();
	*src2 = *(dynamic_cast<MateriaSource*>(src));
	tmp = src2->createMateria("ice");
	bob1->equip(tmp);
	AMateria		*tmp2 = src2->createMateria("ice");
	bob1->equip(tmp2);

	bob1->unequip(-1);
	bob1->unequip(4);
	bob1->unequip(3);
	delete (tmp);
	bob1->unequip(2);
	delete (tmp2);
	bob1->unequip(4);

	tmp = src2->createMateria("ice");
	bob2->equip(tmp);
	tmp = src2->createMateria("cure");
	bob2->equip(tmp);
	bob2->use(2, *me);
	bob2->use(3, *me);
	bob2->use(3, *me);
	std::cout << tmp->getType() << " has " << tmp->getXP() << "XP" << std::endl;

	MateriaSource	*src3 = new MateriaSource();
	*src2 = *src3;
	delete (bob1);
	delete (bob2);
	delete (me);
	delete (src);
	delete (src2);
	delete (src3);

	return (0);
}
