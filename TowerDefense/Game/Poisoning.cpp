#include "Poisoning.h"
#include "Enemy.h"

Poisoning::Poisoning()
{
	remaining_time = thePrefs.GetInt("EffectSettings", "PoisoningTime");
	value = thePrefs.GetInt("EffectSettings", "PoisoningValue");
}

Poisoning::Poisoning(const Poisoning& orig)
{
}

Poisoning::~Poisoning()
{
}

void Poisoning::action(Enemy& en){
	//std::thread interval(&Poisoning::damage, this, std::ref(en));
	//interval.detach();
}

void Poisoning::expired(Enemy& en){
}

void Poisoning::damage(Enemy& en){
	for(int i = 0; i < remaining_time/value; ++i){
		std::this_thread::sleep_for(std::chrono::seconds(value));
		if(!en.get_damage(thePrefs.GetFloat("EffectSettings", "PoisoningDmg"))){
			break;
		}
	}
}

bool Poisoning::tick(Enemy& en){
	if(remaining_time % value == 0){
		if(!en.get_damage(thePrefs.GetFloat("EffectSettings", "PoisoningDmg"))){
			remaining_time = 0;
		}
	}
	Effect::tick(std::ref(en));
}