#include "Poisoning.h"
#include "Enemy.h"
const float damage_per_tick = 50.0;

Poisoning::Poisoning()
{
	remaining_time = 6;
	value = 2;
}

Poisoning::Poisoning(const Poisoning& orig)
{
}

Poisoning::~Poisoning()
{
}

void Poisoning::action(Enemy& en){
	std::thread interval(&Poisoning::damage, this, std::ref(en));
	interval.detach();
}

void Poisoning::expired(Enemy& en){
}

void Poisoning::damage(Enemy& en){
	for(int i = 0; i < remaining_time/value; ++i){
		std::this_thread::sleep_for(std::chrono::seconds(value));
		if(!en.get_damage(damage_per_tick)){
			break;
		}
	}
}