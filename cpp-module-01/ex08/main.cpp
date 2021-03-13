#include "Human.hpp"

int		main(void)
{
	Human	h;

	h.action("melee", "elephant");
	h.action("ranged", "archer");
	h.action("shout", "commander");
	h.action("shoot", "someone");
	return (0);
}
