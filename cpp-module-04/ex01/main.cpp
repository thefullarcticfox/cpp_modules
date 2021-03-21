#include <iostream>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "BFG9000.hpp"
#include "DeathClaw.hpp"

int		main(void)
{
	Character*	me = new Character("me");

	std::cout << *me;

	Enemy*		b = new RadScorpion();

	AWeapon*	pr = new PlasmaRifle();
	AWeapon*	pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);			// radscorp deleted here
	std::cout << *me;

	std::cout << "--------------------------------------------------" <<
		std::endl;

	AWeapon*	bfg = new BFG9000();
	Enemy*		sm = new SuperMutant();
	me->attack(NULL);		// nothing happens
	me->equip(pf);
	std::cout << *me << sm->getType() << " has " << sm->getHP() << "HP" <<
		std::endl;			// 170hp
	me->attack(sm);
	std::cout << *me << sm->getType() << " has " << sm->getHP() << "HP" <<
		std::endl;			// 170 - (50 - 3) = 123hp
	me->equip(bfg);
	std::cout << *me;
	me->attack(b);			// no sigabort because not enough AP
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(sm);			// supermutant deleted here
	std::cout << *me << std::endl;

	Enemy*		death = new DeathClaw();
	std::cout << *me << death->getType() << " has " << death->getHP() << "HP" <<
		std::endl;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(death);		// deathclaw deleted here
	me->equip(NULL);
	me->attack(sm);			// nothing happens
	std::cout << *me;
	delete (pr);
	delete (pf);
	delete (bfg);
	delete (me);

	return (0);
}
