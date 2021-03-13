#include <iostream>
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "MiningBarge.hpp"

int		main(void)
{
	MiningBarge		barge;
	IAsteroid		*aster = new AsteroKreog();
	IAsteroid		*comet = new KoalaSteroid();
	IMiningLaser	*sm1 = new StripMiner();
	IMiningLaser	*dc1 = new DeepCoreMiner();

	barge.equip(NULL);
	barge.equip(sm1);
	std::cout << ">>>>>> 1 StripMiner laser barge" << std::endl;
	std::cout << ">>>>>> Mining " << comet->getName() << std::endl;
	barge.mine(comet);
	std::cout << ">>>>>> Mining " << aster->getName() << std::endl;
	barge.mine(aster);

	barge.equip(dc1);
	std::cout << ">>>>>> 1 Strip and 1 DeepCore miner laser barge" << std::endl;
	std::cout << ">>>>>> Mining " << comet->getName() << std::endl;
	barge.mine(comet);
	std::cout << ">>>>>> Mining " << aster->getName() << std::endl;
	barge.mine(aster);

	barge.equip(dc1);
	barge.equip(sm1);
	std::cout << ">>>>>> 2 Strip and 2 DeepCore miner laser barge" << std::endl;
	std::cout << ">>>>>> Mining " << comet->getName() << std::endl;
	barge.mine(comet);
	std::cout << ">>>>>> Mining " << aster->getName() << std::endl;
	barge.mine(aster);

	barge.equip(sm1);
	barge.equip(sm1);
	std::cout << ">>>>>> 2 Strip and 2 DeepCore miner laser barge " <<
		"(laser overflow attempt)" << std::endl;
	std::cout << ">>>>>> Mining " << comet->getName() << std::endl;
	barge.mine(comet);
	std::cout << ">>>>>> Mining " << aster->getName() << std::endl;
	barge.mine(aster);

	delete (aster);
	delete (comet);
	delete (sm1);
	delete (dc1);
	return (0);
}
