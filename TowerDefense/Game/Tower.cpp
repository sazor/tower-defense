/* 
 * File:   Tower.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:28 PM
 */

#include "Tower.h"

void Tower::setCharacteristics(Characteristics characteristics)
{
        this->characteristics = characteristics;
}

Characteristics Tower::getCharacteristics() const
{
        return characteristics;
}

void Tower::setLevel(int level)
{
        this->level = level;
}

int Tower::getLevel() const
{
        return level;
}

bool Tower::change_position(Point){
	
}