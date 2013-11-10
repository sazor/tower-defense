/* 
 * File:   Lair.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:26 PM
 */

#include "Lair.h"

Lair::Lair()
{
}

Lair::Lair(const Lair& orig)
{
}

Lair::~Lair()
{
}

std::vector<Enemy> Lair::getEnemies() const
{
        return enemies;
}

bool Lair::change_position(Point){
	
}