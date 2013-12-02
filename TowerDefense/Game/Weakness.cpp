#include "Weakness.h"
#include "Enemy.h"

Weakness::Weakness()
{
	remaining_time = thePrefs.GetInt("EffectSettings", "WeaknessTime");
	value = thePrefs.GetInt("EffectSettings", "WeaknessValue");
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

