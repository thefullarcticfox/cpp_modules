#include <iostream>
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int		main(void)
{
	ISpaceMarine*	bob = new TacticalMarine;
	ISpaceMarine*	jim = new AssaultTerminator;

	ISquad*			vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete (vlc);

	std::cout << "----------------------------------------" << std::endl;

	bob = new TacticalMarine;
	jim = new AssaultTerminator;
	Squad			vlc1 = Squad();
	vlc1.push(bob);
	vlc1.push(jim);

	Squad*			vlc2 = new Squad;
	ISpaceMarine*	bob1 = new TacticalMarine;
	ISpaceMarine*	bob2 = new TacticalMarine;
	ISpaceMarine*	jim1 = new AssaultTerminator;
	ISpaceMarine*	jim2 = new AssaultTerminator;
	vlc2->push(bob1);
	vlc2->push(bob2);
	vlc2->push(jim2);
	vlc2->push(jim1);
	vlc2->push(jim1);
	std::cout << std::endl << "vlc1 and vlc2 are a squads of " <<
		vlc1.getCount() << " and " << vlc2->getCount() << " marines" <<
		std::endl << std::endl;
	vlc1 = *vlc2;
	std::cout << std::endl << "vlc2 assigned to vlc1. now vlc1 is a squad of " <<
		vlc1.getCount() << " marines" << std::endl << std::endl;
	for (int i = 0; i < vlc1.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc1.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	*vlc2 = *vlc2;
	Squad			vlc3(*vlc2);
	delete (vlc2);
	std::cout << std::endl << "vlc3 cpyconstructor called with vlc2 as arg. " <<
		"vlc2 deleted. now vlc3 is a squad of " << vlc3.getCount() <<
		" marines" << std::endl << std::endl;
	for (int i = 0; i < vlc3.getCount(); ++i)
	{
		ISpaceMarine* cur = vlc3.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	return (0);
}
