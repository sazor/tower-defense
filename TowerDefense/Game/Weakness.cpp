#include "Weakness.h"
#include "Enemy.h"

Weakness::Weakness()
{
	remaining_time = 5;
	value = 2;
}

Weakness::Weakness(const Weakness& orig)
{
}

Weakness::~Weakness()
{
}

void Weakness::action(Enemy& en){
	en.increase_dmg_factor(value);
}

void Weakness::expired(Enemy& en){
	en.decrease_dmg_factor(value);
}

