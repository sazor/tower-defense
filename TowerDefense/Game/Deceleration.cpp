/* 
 * File:   Deceleration.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:32 PM
 */

#include "Deceleration.h"
#include "Enemy.h"

Deceleration::Deceleration()
{
	remaining_time = 4;
	value = 1;
}

Deceleration::Deceleration(const Deceleration& orig)
{
}

Deceleration::~Deceleration()
{
}

void Deceleration::action(Enemy& en){
	en.decrease_speed(value);
}

void Deceleration::expired(Enemy& en){
	en.increase_speed(value);
}

